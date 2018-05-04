//
// Created by noreasonexception on 4/14/18.
//

#include <iostream>
#include "AbstractRTSPClientSubsystem.h"
#include "../MainWindow/Panels/StreamPanel/LogPanel/LogPanel.h"
#include "../res/Suppliers/LogSuppliers.h"
#include "../MainWindow/Panels/StreamPanel/DataPanel/DataPanel.h"

AbstractRTSPClientSubsystem::AbstractRTSPClientSubsystem() :
        dataSupplier(DataPanel::getInstance()->createSupplier(ABSTRACT_RTSP_CLIENT_SUPPLIER)),
        supplier(LogPanel::getInstance()->createSupplier(ABSTRACT_RTSP_CLIENT_SUPPLIER)){
    consumerLocker=new QMutex();
    self_supplier= nullptr;
}

OptionSupplier *AbstractRTSPClientSubsystem::createSupplier(QString supplierName) {
    return new OptionSupplier(supplierName,this);
}
/****
 * This accept is called by every submitted OptionSupplier .
 * @param supplier the supplier that submits this information
 * @param info      The info* pointer accepts one of the following object types
 *                  class LatencyOption*       (InformationObject/Option/ChildOptions/LatencyOption.h)
 *                      #This object provides the video-latency option to subsystem
 *                  class LocationOption*      (InformationObject/Option/ChildOptions/LocationOption.h)
 *                      #This object provides the Ip address of Streaming Server
 *                  class ResolutionOption*    (InformationObject/Option/ChildOptions/ResolutionOption.h)
 *                      #This object provides the Resolution(width/height) of streaming server
 *                  class ClientStatusOption*  (InformationObject/Option/ChildOptions/ClientStatusOption.h)
 *                      #This object provides from GUI-Space the subsystem status @see AbstractRTSPClientSubsystem.h
 *                  class WindowHandlerOption* (InformationObject/Option/ChildOptions/WindowHandleOption.h)
 *                      #This object provides the window handle , used by library to detect the Qt Window!
 */
void AbstractRTSPClientSubsystem::accept(InformationObjectSupplier *supplier, InformationObject *info) {
    QMutexLocker *locker= nullptr;
    if(supplier!=getSelf_supplier())
        locker=new QMutexLocker(consumerLocker);
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
    if(locker)delete locker;

}

LogSupplier *AbstractRTSPClientSubsystem::getLogSupplier() const {
    return supplier;
}
DataSupplier *AbstractRTSPClientSubsystem::getDataSupplier() const {
    return dataSupplier;
}

OptionSupplier *AbstractRTSPClientSubsystem::getSelf_supplier() {
    if(!self_supplier)self_supplier=createSupplier("AbstractRTSPClientSelfSupplier");
    return self_supplier;
}



