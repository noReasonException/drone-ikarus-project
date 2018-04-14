//
// Created by noreasonexception on 4/14/18.
//

#include "AlanDefaultRTSPClientSubsystem.h"
#include "../../InformationObject/Log/Log.h"

void AlanDefaultRTSPClientSubsystem::onLatencySettingChangedHandler(class LatencyOption *option) {
    if(isNullThenLog(option,"onLatencySettingChangedHandler() call , LatencyOption* object expected"))return;
    settings.setValue(ALAN_DEFAULT_RTSP_QSETTING_LATENCY,option->getLatency());
    delete option;
}

void AlanDefaultRTSPClientSubsystem::onResolutionSettingChangedHandler(class ResolutionOption *option) {
    if(isNullThenLog(option,"onResolutionSettingChangedHandler() call , ResolutionOption* object expected"))return;
    settings.setValue(ALAN_DEFAULT_RTSP_QSETTING_RESOLUTION_WIDTH,option->getWidth());
    settings.setValue(ALAN_DEFAULT_RTSP_QSETTING_RESOLUTION_HEIGHT,option->getHeight());
    delete option;
}

void AlanDefaultRTSPClientSubsystem::onClientStatusSettingChangedHandler(class ClientStatusOption *option) {
    if(isNullThenLog(option,"onClientStatusSettingChangedHandler() call , ClientStatusOption* object expected"))return;
    if(!isWindowHandleDefined){
        getSupplier()->send(new Log(
                "test",
                time(NULL),
                "cant change state before set WindowHandler",
                getSupplier()
        ));
        return;
    }
    isClientStatusDefined=true;
    currentStatus =option->getStatus();
    delete option;

}

void AlanDefaultRTSPClientSubsystem::onWindowHandlerSettingChangedHandler(class WindowHandleOption *option) {
    if(isNullThenLog(option,"onWindowHandlerSettingChangedHandler() call , WindowHandleOption* object expected"))return;
    if(isWindowHandleDefined){
        getSupplier()->send(new Log(
                "test",
                time(NULL),
                "already defined handler",
                getSupplier()
        ));
        return;
    }
    isWindowHandleDefined=true;
    windowHandle=option->getWindowHanle();
    delete option;
}

bool AlanDefaultRTSPClientSubsystem::isNullThenLog(void *ptr,QString message) {
    if(!ptr){
        getSupplier()->send(new Log(
                "test",
                time(NULL),
                "invalid object given ("+message+")",getSupplier()));
        return true;
    }
    return false;
}
