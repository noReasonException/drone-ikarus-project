//
// Created by noreasonexception on 4/14/18.
//

#include "AbstractRTSPClientSubsystem.h"
#include "../MainWindow/Panels/StreamPanel/LogPanel/LogPanel.h"
#include "../misc/generic_text/AlanMainWindowMisc.h"
#include "../InformationObject/Option/Option.h"

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
    switch(optionObject->getType()){
        case OptionType::LatencyOption:     {onLatencySettingChangedHandler();break;}
        case OptionType::ResolutionOption:  {onResolutionSettingChangedHandler();break;}
        case OptionType::ClientStatusOption:{onClientStatusSettingChangedHandler();break;}
        default:{
            getSupplier()->send(new Log(
                    "test",time(NULL),"invalid OptionType",getSupplier()));
        }
    }

}

LogSupplier *AbstractRTSPClientSubsystem::getSupplier() const {
    return supplier;
}

AbstractRTSPClientSubsystem::AbstractRTSPClientSubsystem() :
        supplier(LogPanel::getInstance(LOGS_PANEL_TITLE)->createSupplier("AbstractRTSPClientSubSystem")) {}

