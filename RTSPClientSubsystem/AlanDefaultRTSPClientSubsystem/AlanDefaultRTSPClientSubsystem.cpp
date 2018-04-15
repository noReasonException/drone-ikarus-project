//
// Created by noreasonexception on 4/14/18.
//

#include <gst/gst.h>
#include "AlanDefaultRTSPClientSubsystem.h"
#include "../../InformationObject/Log/Log.h"
#include "../../misc/Suppliers/LogSuppliers.h"
#include "common.h"
extern "C" gboolean generic_initializer(const int flags, int num, ...);

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
    ClientStatus  status = option->getStatus();
    delete option;
    if(callProperStatusHandler(status)){
        isClientStatusDefined=true;
        currentStatus =status;
        return true;

    }
    return false;

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

bool AlanDefaultRTSPClientSubsystem::callProperStatusHandler(ClientStatus status) {
    bool succeed;
    switch(status){
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
    if(!(currentStatus==ClientStatus::Client_NONE||currentStatus==ClientStatus::Client_STOP)){
        getSupplier()->send(new Log(
                ABSTRACT_RTSP_CLIENT_STATE_CHANGE_FAILURE_LOG,
                time(NULL),
                INVALID_CURRENT_STATE_TO_SWITCH_DESC_LOG,
                getSupplier()));
        return false;
    }
    if(!initializeGstreamer()){
        getSupplier()->send(new Log(
                ABSTRACT_RTSP_CLIENT_STATE_CHANGE_FAILURE_LOG,
                time(NULL),
                GSTREAMER_INIT_FAILED_DESC_LOG,
                getSupplier()));
        return false;
    }
    //g_main_loop_run(mainLoop);
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
    return currentStatus==Client_PLAY;
}

bool AlanDefaultRTSPClientSubsystem::onStopStatusRequest() {
    getSupplier()->send(new Log(
            "STOP",
            time(NULL),
            "-",
            getSupplier()));
    return currentStatus==Client_PLAY;
}

bool AlanDefaultRTSPClientSubsystem::initializeGstreamer() {
    GError*err;
    char sprintf_buffer[50];

    /*Initialization check of gstreamer*/
    if(!gst_init_check(0,0,&err)){
        sprintf(sprintf_buffer,"%s",err->message);
        getSupplier()->send(new Log("Gstreamer init fail", time(NULL), sprintf_buffer, getSupplier()));
        return false;
    }
    /*Print current version...*/
    gst_version(&major,&minor,&nano,&pico);
    sprintf(sprintf_buffer,"Gstreamer version %d.%d.%d.%d",major,minor,nano,pico);
    getSupplier()->send(new Log("Gstreamer Version", time(NULL), sprintf_buffer, getSupplier()));

    /*Initialize GMainLoop*/
    if(!(mainLoop=g_main_loop_new(NULL,FALSE))){
        getSupplier()->send(new Log("Gstreamer init fail", time(NULL), "g_main_loop_new fail", getSupplier()));
        return false;

    }
    getSupplier()->send(new Log("MainLoop initialized", time(NULL), "-", getSupplier()));
    /*Initialize Pipeline*/
    if(!(pipeline=gst_pipeline_new("AlanDefaultRTSPClientSubSystem"))){
        getSupplier()->send(new Log("Gstreamer init fail", time(NULL), "gst_pipeline_new fail", getSupplier()));
        return false;
    }
    getSupplier()->send(new Log("Pipeline initialized", time(NULL), "-", getSupplier()));
    /*Initialize elements*/

    if(!_utillLogHandler(_initializeFactories(),
                     GSTREAMER_FACTORIES_INIT_SUCCESS_LOG,GSTREAMER_FACTORIES_INIT_SUCCESS_DESC_LOG))return false;
    else if(!_utillLogHandler(_initializeElements(),
                     GSTREAMER_ELEMENTS_INIT_SUCCESS_LOG,GSTREAMER_ELEMENTS_INIT_SUCCESS_DESC_LOG))return false;
    else if(!_utillLogHandler(_initializeConnections(),
                     GSTREAMER_ELEMENTS_LINK_SUCCESS_LOG,GSTREAMER_ELEMENTS_LINK_SUCCESS_DESC_LOG))return false;
    else if(!_utillLogHandler(_applyProperties(),
                     GSTREAMER_APPLY_PROPERTIES_SUCCESS_LOG,GSTREAMER_APPLY_PROPERTIES_SUCCESS_DESC_LOG))return false;




    return true;
}

bool AlanDefaultRTSPClientSubsystem::_initializeFactories() {
    /*Initialize Factories...*/
    return generic_initializer((GIN_FREE_STRING_AFTER | GIN_INITIALIZE_TYPE_FACTORY), 6,
                             &gstrtspsrc_fact, g_strdup("rtspsrc"),
                             &queue_fact,g_strdup("queue"),
                             &rtph264depayloader_fact,g_strdup("rtph264depay"),
                             &decodebin_fact,g_strdup("decodebin"),
                             &videoconvert_fact,g_strdup("videoconvert"),
                             &ximagesink_fact,g_strdup("ximagesink"));

}

bool AlanDefaultRTSPClientSubsystem::_initializeElements() {
    return(generic_initializer((GIN_FREE_STRING_AFTER | GIN_INITIALIZE_TYPE_ELEMENT), 6,
                             gstrtspsrc_fact, &gstrtspsrc_elem, g_strdup("rtsp-src"),
                             queue_fact,&queue_elem,g_strdup("buffer-queue-eleme"),
                             rtph264depayloader_fact,&rtph264depayloader_elem,g_strdup("depay-elem"),
                             decodebin_fact,&decodebin_elem,g_strdup("decodebin-element"),
                             videoconvert_fact,&videoconvert_elem,g_strdup("videoconvert-element"),
                             ximagesink_fact,&ximagessink_elem,g_strdup("ximagesink-elem")));
}

bool AlanDefaultRTSPClientSubsystem::_initializeConnections() {
    gst_bin_add_many(GST_BIN(pipeline),
                     gstrtspsrc_elem,           ///packets from network under RTSP
                     queue_elem,                ///Buffer
                     rtph264depayloader_elem,         ///depayloader to data
                     decodebin_elem,            ///convert h264 to video
                     videoconvert_elem,         ///raw video
                     ximagessink_elem,NULL);  ///screen
    return gst_element_link_many(
                    queue_elem,
                    rtph264depayloader_elem,
                    decodebin_elem,NULL)&&
                                            ///decodebin -> videoconvert connection happens on on-pad event lisener
                    gst_element_link(
                     videoconvert_elem,
                     ximagessink_elem);
}

bool AlanDefaultRTSPClientSubsystem::_utillLogHandler(bool status, const QString &onSuccessTitle, const QString &onSuccessMsg) {
    if(status)getSupplier()->send(new Log(onSuccessTitle, time(NULL), onSuccessMsg ,getSupplier()));
    return status;
}

bool AlanDefaultRTSPClientSubsystem::_applyProperties() {
    g_object_set(G_OBJECT(gstrtspsrc_elem),"location",settings.value(ALAN_DEFAULT_RTSP_QSETTING_LOCATION).toString().toStdString().c_str());
    g_object_set(G_OBJECT(ximagessink_elem),"sync",FALSE);
    g_object_set(G_OBJECT(queue_elem),"max-size-bytes",30);
    g_object_set(G_OBJECT(queue_elem),"max-size-buffers",2);
    g_object_set(G_OBJECT(queue_elem),"max-size-time",settings.value(ALAN_DEFAULT_RTSP_QSETTING_LATENCY).toInt());
    return true;
}
