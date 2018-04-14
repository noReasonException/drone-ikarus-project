//
// Created by noreasonexception on 4/14/18.
//

#include "AbstractRTSPClientSubsystem.h"
#include "../MainWindow/Panels/StreamPanel/LogPanel/LogPanel.h"
#include "../misc/generic_text/AlanMainWindowMisc.h"

OptionSupplier *AbstractRTSPClientSubsystem::createSupplier(QString supplierName) {
    return new OptionSupplier(supplierName,this);
}

void AbstractRTSPClientSubsystem::accept(InformationObjectSupplier *supplier, InformationObject *info) {
    Option*optionObject;
    if(!(optionObject= dynamic_cast<Option*>(info))){
        getSupplier()->send(new Log(
                "test",time(NULL),"invalid-cast",getSupplier()));
        return;
    }
    /*switch(optionObject->getType()){
        case OptionType::LatencyOption:      {onLatencySettingChangedHandler(dynamic_cast<LatencyOption*>(optionObject));break;}
        case OptionType::ResolutionOption:   {onResolutionSettingChangedHandler(dynamic_cast<ResolutionOption*>(optionObject));break;}
        case OptionType::ClientStatusOption: {onClientStatusSettingChangedHandler(dynamic_cast<ClientStatusOption*>(optionObject));break;}
        case OptionType::WindowHandlerOption:{onWindowHandlerSettingChangedHandler(dynamic_cast<WindowHandleOption*>(optionObject));break;}
        default:{
            getSupplier()->send(new Log(
                    "test",time(NULL),"invalid OptionType",getSupplier()));
        }
    }*/

}

LogSupplier *AbstractRTSPClientSubsystem::getSupplier() const {
    return supplier;
}

AbstractRTSPClientSubsystem::AbstractRTSPClientSubsystem() :
        supplier(LogPanel::getInstance(LOGS_PANEL_TITLE)->createSupplier("AbstractRTSPClientSubSystem")) {}

