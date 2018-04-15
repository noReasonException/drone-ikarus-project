//
// Created by noreasonexception on 4/14/18.
//

#include "AlanDefaultRTSPClientSubsystem.h"
#include "../../InformationObject/Log/Log.h"
#include "../../misc/Suppliers/LogSuppliers.h"

bool AlanDefaultRTSPClientSubsystem::onLatencySettingChangedHandler(class LatencyOption *option) {
    if(isNullThenLog(option,
                     INVALID_ARG_LATENCYOPTION_EXPECTED_LOG))return false;
    settings.setValue(ALAN_DEFAULT_RTSP_QSETTING_LATENCY,option->getLatency());
    delete option;
    return true;
}

bool AlanDefaultRTSPClientSubsystem::onResolutionSettingChangedHandler(class ResolutionOption *option) {
    if(isNullThenLog(option,
                     INVALID_ARG_RESOLUTIONOPTION_EXPECTED_LOG))return false;
    settings.setValue(ALAN_DEFAULT_RTSP_QSETTING_RESOLUTION_WIDTH,option->getWidth());
    settings.setValue(ALAN_DEFAULT_RTSP_QSETTING_RESOLUTION_HEIGHT,option->getHeight());
    delete option;
    return true;
}

bool AlanDefaultRTSPClientSubsystem::onClientStatusSettingChangedHandler(class ClientStatusOption *option) {
    if(isNullThenLog(option,
                     INVALID_ARG_CLIENTSTATUSOPTION_EXPECTED_LOG))return false;
    if(!isWindowHandleDefined){
        getSupplier()->send(new Log(
                UNABLE_TO_CHANGE_STATE_LOG,
                time(NULL),
                STATE_CHANGE_REQUEST_WITHOUT_WINDOWHANDLER_SET_DESC_LOG,
                getSupplier()));
        return false;
    }
    isClientStatusDefined=true;
    currentStatus =option->getStatus();
    callProperStatusHandler();
    delete option;
    return true;

}

bool AlanDefaultRTSPClientSubsystem::onWindowHandlerSettingChangedHandler(class WindowHandleOption *option) {
    if(isNullThenLog(option,
                     INVALID_ARG_WINDOWHANDLEOPTION_EXPECTED_LOG))return false;
    if(isWindowHandleDefined){
        getSupplier()->send(new Log(
                INVALID_HANDLER_CALL_LOG,
                time(NULL),
                WINDOWHANDLER_ALREADY_DEFINED_DESC_LOG,
                getSupplier()
        ));
        return false;
    }
    isWindowHandleDefined=true;
    windowHandle=option->getWindowHanle();
    delete option;
    return true;
}

bool AlanDefaultRTSPClientSubsystem::onLocationSettingChangedHandler(class LocationOption *option) {
    if(isNullThenLog(option,
                     INVALID_ARG_LOCATION_EXPECTED_LOG))return false;
    settings.setValue(ALAN_DEFAULT_RTSP_QSETTING_LOCATION,option->getIpLocation());
    delete option;
    return true;


}

bool AlanDefaultRTSPClientSubsystem::isNullThenLog(void *ptr,
                                                   const QString &onErrorMessage) {
    if(!ptr){
        getSupplier()->send(new Log(
                INVALID_ARG_IN_ACCEPT_LOG,
                time(NULL),
                onErrorMessage,
                getSupplier()));
        return true;
    }
    return false;
}

AlanDefaultRTSPClientSubsystem::AlanDefaultRTSPClientSubsystem() : currentStatus(Client_NONE) {}

bool AlanDefaultRTSPClientSubsystem::callProperStatusHandler() {
    bool succeed;
    switch(currentStatus){
        case Client_PAUSE   :succeed=onPauseStatusRequest();return succeed;
        case Client_START   :succeed=onStartStatusRequest();return succeed;
        case Client_PLAY    :succeed=onPlayStatusRequest() ;return succeed;
        case Client_STOP    :succeed=onStopStatusRequest() ;return succeed;
        case Client_NONE:{
            getSupplier()->send(new Log(
                    ABSTRACT_RTSP_CLIENT_STATE_CHANGE_FAILURE_LOG,
                    time(NULL),
                    NONE_STATE_REQUESTED_DESC_LOG,
                    getSupplier()));
            return false;}
        default:{
            getSupplier()->send(new Log(
                    ABSTRACT_RTSP_CLIENT_STATE_CHANGE_FAILURE_LOG,
                    time(NULL),
                    UNNKNOWN_STATE_REQUESTED_DESC_LOG,
                    getSupplier()));
            return false;}

    }

}

bool AlanDefaultRTSPClientSubsystem::onStartStatusRequest() {
    getSupplier()->send(new Log(
            "START",
            time(NULL),
            "-",
            getSupplier()));
    return true;

}

bool AlanDefaultRTSPClientSubsystem::onPlayStatusRequest() {
    getSupplier()->send(new Log(
            "PLAY",
            time(NULL),
            "-",
            getSupplier()));
    return true;
}

bool AlanDefaultRTSPClientSubsystem::onPauseStatusRequest() {
    getSupplier()->send(new Log(
            "PAUSE",
            time(NULL),
            "-",
            getSupplier()));
    return true;
}

bool AlanDefaultRTSPClientSubsystem::onStopStatusRequest() {
    getSupplier()->send(new Log(
            "STOP",
            time(NULL),
            "-",
            getSupplier()));
    return true;
}
