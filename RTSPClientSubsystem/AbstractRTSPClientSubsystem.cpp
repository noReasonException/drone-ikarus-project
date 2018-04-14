//
// Created by noreasonexception on 4/14/18.
//

#include "AbstractRTSPClientSubsystem.h"
#include "../MainWindow/Panels/StreamPanel/LogPanel/LogPanel.h"
#include "../misc/generic_text/AlanMainWindowMisc.h"
#include "../misc/Suppliers/LogSuppliers.h"

OptionSupplier *AbstractRTSPClientSubsystem::createSupplier(QString supplierName) {
    return new OptionSupplier(supplierName,this);
}

void AbstractRTSPClientSubsystem::accept(InformationObjectSupplier *supplier, InformationObject *info) {
    Option*optionObject;
    if(!(optionObject= dynamic_cast<Option*>(info))){
        getSupplier()->send(new Log(
                INVALID_ARG_IN_ACCEPT_LOG,
                time(NULL),
                INVALID_INFORMATION_OBJECT_PROVIDED_IN_ACCEPT_CALL_DESC_LOG,
                getSupplier()));
        return;
    }
    switch(optionObject->getType()){
        case OptionType::LatencyOption:      {onLatencySettingChangedHandler(dynamic_cast<class LatencyOption*>(optionObject));break;}
        case OptionType::ResolutionOption:   {onResolutionSettingChangedHandler(dynamic_cast<class ResolutionOption*>(optionObject));break;}
        case OptionType::ClientStatusOption: {onClientStatusSettingChangedHandler(dynamic_cast<class ClientStatusOption*>(optionObject));break;}
        case OptionType::WindowHandlerOption:{onWindowHandlerSettingChangedHandler(dynamic_cast<class WindowHandleOption*>(optionObject));break;}
        default:{
            getSupplier()->send(new Log(
                    INVALID_ARG_IN_ACCEPT_LOG,
                    time(NULL),
                    UNKNOWN_DERIVED_TYPE_OF_OPTION_PROVIDED_IN_ACCEPT_CALL_DESC_LOG,
                    getSupplier()));
        }
    }

}

LogSupplier *AbstractRTSPClientSubsystem::getSupplier() const {
    return supplier;
}

AbstractRTSPClientSubsystem::AbstractRTSPClientSubsystem() :
        supplier(LogPanel::getInstance(LOGS_PANEL_TITLE)->createSupplier(ABSTRACT_RTSP_CLIENT_SUPPLIER)) {}

