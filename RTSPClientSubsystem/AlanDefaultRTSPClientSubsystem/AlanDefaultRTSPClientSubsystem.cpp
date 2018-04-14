//
// Created by noreasonexception on 4/14/18.
//

#include "AlanDefaultRTSPClientSubsystem.h"
#include "../../InformationObject/Log/Log.h"
#include "../../misc/Suppliers/LogSuppliers.h"

void AlanDefaultRTSPClientSubsystem::onLatencySettingChangedHandler(class LatencyOption *option) {
    if(isNull(option, INVALID_ARG_LATENCYOPTION_EXPECTED_LOG))return;
    settings.setValue(ALAN_DEFAULT_RTSP_QSETTING_LATENCY,option->getLatency());
    delete option;
}

void AlanDefaultRTSPClientSubsystem::onResolutionSettingChangedHandler(class ResolutionOption *option) {
    if(isNull(option, INVALID_ARG_RESOLUTIONOPTION_EXPECTED_LOG))return;
    settings.setValue(ALAN_DEFAULT_RTSP_QSETTING_RESOLUTION_WIDTH,option->getWidth());
    settings.setValue(ALAN_DEFAULT_RTSP_QSETTING_RESOLUTION_HEIGHT,option->getHeight());
    delete option;
}

void AlanDefaultRTSPClientSubsystem::onClientStatusSettingChangedHandler(class ClientStatusOption *option) {
    if(isNull(option, INVALID_ARG_CLIENTSTATUSOPTION_EXPECTED_LOG))return;
    if(!isWindowHandleDefined){
        getSupplier()->send(new Log(
                UNABLE_TO_CHANGE_STATE_LOG,
                time(NULL),
                STATE_CHANGE_REQUEST_WITHOUT_WINDOWHANDLER_SET_DESC_LOG,
                getSupplier()));
        return;
    }
    isClientStatusDefined=true;
    currentStatus =option->getStatus();
    delete option;

}

void AlanDefaultRTSPClientSubsystem::onWindowHandlerSettingChangedHandler(class WindowHandleOption *option) {
    if(isNull(option, INVALID_ARG_WINDOWHANDLEOPTION_EXPECTED_LOG))return;
    if(isWindowHandleDefined){
        getSupplier()->send(new Log(
                INVALID_HANDLER_CALL_LOG,
                time(NULL),
                WINDOWHANDLER_ALREADY_DEFINED_DESC_LOG,
                getSupplier()
        ));
        return;
    }
    isWindowHandleDefined=true;
    windowHandle=option->getWindowHanle();
    delete option;
}

bool AlanDefaultRTSPClientSubsystem::isNull(void *ptr, QString message) {
    if(!ptr){
        getSupplier()->send(new Log(
                INVALID_ARG_IN_ACCEPT_LOG,
                time(NULL),
                message,
                getSupplier()));
        return true;
    }
    getSupplier()->send(new Log(
            SUCCESS_IN_OPTION_CHANGE_LOG,
            time(NULL),
            SUCCESS_IN_OPTION_CHANGE_DESC_LOG,
            getSupplier()));
    return false;
}

