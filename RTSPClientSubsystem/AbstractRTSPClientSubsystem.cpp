//
// Created by noreasonexception on 4/14/18.
//

#include <iostream>
#include "AbstractRTSPClientSubsystem.h"
#include "../MainWindow/Panels/StreamPanel/LogPanel/LogPanel.h"
#include "../misc/generic_text/AlanMainWindowMisc.h"
#include "../misc/Suppliers/LogSuppliers.h"
#include "../MainWindow/Panels/StreamPanel/DataPanel/DataPanel.h"

OptionSupplier *AbstractRTSPClientSubsystem::createSupplier(QString supplierName) {
    return new OptionSupplier(supplierName,this);
}

void AbstractRTSPClientSubsystem::accept(InformationObjectSupplier *supplier, InformationObject *info) {
    QMutexLocker locker(consumerLocker);
    Option*optionObject;
    QString handlerName;
    bool handlerStatus=false;
    if(!(optionObject= dynamic_cast<Option*>(info))){
        getLogSupplier()->send(new Log(
                INVALID_ARG_IN_ACCEPT_LOG,
                time(NULL),
                INVALID_INFORMATION_OBJECT_PROVIDED_IN_ACCEPT_CALL_DESC_LOG,
                getLogSupplier()));
        return;
    }
    switch(optionObject->getType()){
        case OptionType::LatencyOption:      {handlerStatus=onLatencySettingChangedHandler(dynamic_cast<class LatencyOption*>(optionObject));handlerName=OPTION_CHANGED_SUCCESS_LATENCYOPTION_DESC_LOG;break;}
        case OptionType::LocationOption:     {handlerStatus=onLocationSettingChangedHandler(dynamic_cast<class LocationOption *>(info));handlerName=OPTION_CHANGED_SUCCESS_LOCATION_DESC_LOG;break;}
        case OptionType::ResolutionOption:   {handlerStatus=onResolutionSettingChangedHandler(dynamic_cast<class ResolutionOption*>(optionObject));handlerName=OPTION_CHANGED_SUCCESS_RESOLUTIONOPTION_DESC_LOG;break;}
        case OptionType::ClientStatusOption: {handlerStatus=onClientStatusSettingChangedHandler(dynamic_cast<class ClientStatusOption*>(optionObject));handlerName=OPTION_CHANGED_SUCCESS_CLIENTSTATUSOPTION_DESC_LOG;break;}
        case OptionType::WindowHandlerOption:{handlerStatus=onWindowHandlerSettingChangedHandler(dynamic_cast<class WindowHandleOption*>(optionObject));handlerName=OPTION_CHANGED_SUCCESS_WINDOWHANDLEOPTION_DESC_LOG;break;}
        default:{
            getLogSupplier()->send(new Log(
                    INVALID_ARG_IN_ACCEPT_LOG,
                    time(NULL),
                    UNKNOWN_DERIVED_TYPE_OF_OPTION_PROVIDED_IN_ACCEPT_CALL_DESC_LOG,
                    getLogSupplier()));
        }
    }
    if(handlerStatus){
        getLogSupplier()->send(new Log(
                SUCCESS_IN_OPTION_CHANGE_LOG,
                time(NULL),
                handlerName,
                getLogSupplier()));
    }
    delete info;

}

LogSupplier *AbstractRTSPClientSubsystem::getLogSupplier() const {
    return supplier;
}
DataSupplier *AbstractRTSPClientSubsystem::getDataSupplier() const {
    return dataSupplier;
}

AbstractRTSPClientSubsystem::AbstractRTSPClientSubsystem() :
        dataSupplier(DataPanel::getInstance()->createSupplier(ABSTRACT_RTSP_CLIENT_SUPPLIER)),
        supplier(LogPanel::getInstance()->createSupplier(ABSTRACT_RTSP_CLIENT_SUPPLIER)){
    consumerLocker=new QMutex();
}

