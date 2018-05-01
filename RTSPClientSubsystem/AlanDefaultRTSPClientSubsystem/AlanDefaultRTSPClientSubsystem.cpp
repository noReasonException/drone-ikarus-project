//
// Created by noreasonexception on 4/14/18.
//

#include <gst/gst.h>
#include <iostream>
#include "AlanDefaultRTSPClientSubsystem.h"
#include "../../InformationObject/Log/Log.h"
#include "../../misc/Suppliers/LogSuppliers.h"
#include "common.h"
#include "../../InformationObject/Data/Data.h"

extern "C" gboolean     generic_initializer(const int flags, int num, ...);
extern "C" gboolean     generic_bus_handler(GstBus *bus, GstMessage *msg, gpointer pipeline);
extern "C" void on_pad_added_decodebin_listener(GstElement*obj,GstPad*arg0,gpointer videoconvert);
extern "C" void on_pad_added_rtspsrc_listener(GstElement*obj,GstPad*arg0,gpointer queue_element);
extern "C" GstPadProbeReturn on_timestamp_export_probe_triggered(GstPad *pad, GstPadProbeInfo *info, gpointer user_data) ;

bool AlanDefaultRTSPClientSubsystem::onLatencySettingChangedHandler(class LatencyOption *option) {
    if(isNullThenLog(option,
                     INVALID_ARG_LATENCYOPTION_EXPECTED_LOG))return false;
    settings.setValue(ALAN_DEFAULT_RTSP_QSETTING_LATENCY,option->getLatency());
    return true;
}

bool AlanDefaultRTSPClientSubsystem::onResolutionSettingChangedHandler(class ResolutionOption *option) {
    if(isNullThenLog(option,
                     INVALID_ARG_RESOLUTIONOPTION_EXPECTED_LOG))return false;
    settings.setValue(ALAN_DEFAULT_RTSP_QSETTING_RESOLUTION_WIDTH,option->getWidth());
    settings.setValue(ALAN_DEFAULT_RTSP_QSETTING_RESOLUTION_HEIGHT,option->getHeight());
    return true;
}

bool AlanDefaultRTSPClientSubsystem::onClientStatusSettingChangedHandler(class ClientStatusOption *option) {
    if(isNullThenLog(option,
                     INVALID_ARG_CLIENTSTATUSOPTION_EXPECTED_LOG))return false;
    if(!isWindowHandleDefined){
        getLogSupplier()->send(new Log(
                UNABLE_TO_CHANGE_STATE_LOG,
                time(NULL),
                STATE_CHANGE_REQUEST_WITHOUT_WINDOWHANDLER_SET_DESC_LOG,
                getLogSupplier()));
        return false;
    }
    if(callProperStatusHandler(option->getStatus())){
        isClientStatusDefined=true;
        this->currentStatus=option->getStatus();
        return true;

    }
    return false;


}

bool AlanDefaultRTSPClientSubsystem::onWindowHandlerSettingChangedHandler(class WindowHandleOption *option) {
    if(isNullThenLog(option,
                     INVALID_ARG_WINDOWHANDLEOPTION_EXPECTED_LOG))return false;
    if(isWindowHandleDefined){
        getLogSupplier()->send(new Log(
                INVALID_HANDLER_CALL_LOG,
                time(NULL),
                WINDOWHANDLER_ALREADY_DEFINED_DESC_LOG,
                getLogSupplier()
        ));
        return false;
    }
    isWindowHandleDefined=true;
    windowHandle=option->getWindowHanle();
    return true;
}

bool AlanDefaultRTSPClientSubsystem::onLocationSettingChangedHandler(class LocationOption *option) {
    if(isNullThenLog(option,
                     INVALID_ARG_LOCATION_EXPECTED_LOG))return false;
    settings.setValue(ALAN_DEFAULT_RTSP_QSETTING_LOCATION,option->getIpLocation());
    return true;


}

bool AlanDefaultRTSPClientSubsystem::isNullThenLog(void *ptr,
                                                   const QString &onErrorMessage) {
    if(!ptr){
        getLogSupplier()->send(new Log(
                INVALID_ARG_IN_ACCEPT_LOG,
                time(NULL),
                onErrorMessage,
                getLogSupplier()));
        return true;
    }
    return false;
}

AlanDefaultRTSPClientSubsystem::AlanDefaultRTSPClientSubsystem() : currentStatus(Client_NONE) {
    mainLoopThread=new class MainLoopThread();

}

bool AlanDefaultRTSPClientSubsystem::callProperStatusHandler(ClientStatus status) {
    bool succeed;
    switch(status){
        case Client_PAUSE   :succeed=onPauseStatusRequest();std::cout<<"PAUSE"<<succeed<<std::endl;return succeed;break;
        case Client_START   :succeed=onStartStatusRequest();std::cout<<"START"<<succeed<<std::endl;return succeed;break;
        case Client_PLAY    :succeed=onPlayStatusRequest() ;std::cout<<"PLAY"<<succeed<<std::endl;return succeed;break;
        case Client_STOP    :succeed=onStopStatusRequest() ;std::cout<<"STOP"<<succeed<<std::endl;return succeed;break;
        case Client_NONE:{
            getLogSupplier()->send(new Log(
                    ABSTRACT_RTSP_CLIENT_STATE_CHANGE_FAILURE_LOG,
                    time(NULL),
                    NONE_STATE_REQUESTED_DESC_LOG,
                    getLogSupplier()));
            return false;}
        default:{
            getLogSupplier()->send(new Log(
                    ABSTRACT_RTSP_CLIENT_STATE_CHANGE_FAILURE_LOG,
                    time(NULL),
                    UNNKNOWN_STATE_REQUESTED_DESC_LOG,
                    getLogSupplier()));
            return false;}

    }

}

bool AlanDefaultRTSPClientSubsystem::onStartStatusRequest() {

    if(currentStatus!=Client_NONE){ return false; }
    if(!initializeGstreamer()){
        getLogSupplier()->send(new Log(
                ABSTRACT_RTSP_CLIENT_STATE_CHANGE_FAILURE_LOG,
                time(NULL),
                GSTREAMER_INIT_FAILED_DESC_LOG,
                getLogSupplier()));
        return false;
    }
    return true;

}

bool AlanDefaultRTSPClientSubsystem::onPlayStatusRequest() {
    if(currentStatus!=Client_START&&currentStatus!=Client_PAUSE) {
        return false;
    }
    mainLoopThread->setLoop(mainLoop)->start();
    gst_element_set_state(GST_ELEMENT(pipeline),GST_STATE_PLAYING);
    //g_main_loop_run(mainLoop);

    return true;
}

bool AlanDefaultRTSPClientSubsystem::onPauseStatusRequest() {

    if(currentStatus!=Client_PLAY)
        return false;
    gst_element_set_state(pipeline,GST_STATE_PAUSED);
    g_main_loop_quit(mainLoop);
    return true;
}

bool AlanDefaultRTSPClientSubsystem::onStopStatusRequest() {
    //if play , then pause first
    std::cout<<"CURR STATUS IS"<<currentStatus<<std::endl;

    return true;
}

bool AlanDefaultRTSPClientSubsystem::initializeGstreamer() {
    GError*err;
    char sprintf_buffer[50];

    /*Initialization check of gstreamer*/
    if(!gst_init_check(0,0,&err)){
        sprintf(sprintf_buffer,"%s",err->message);
        getLogSupplier()->send(new Log("Gstreamer init fail", time(NULL), sprintf_buffer, getLogSupplier()));
        return false;
    }
    /*Print current version...*/
    gst_version(&major,&minor,&nano,&pico);
    sprintf(sprintf_buffer,"Gstreamer version %d.%d.%d.%d",major,minor,nano,pico);
    getLogSupplier()->send(new Log("Gstreamer Version", time(NULL), sprintf_buffer, getLogSupplier()));

    /*Initialize GMainLoop*/
    if(!(mainLoop=g_main_loop_new(NULL,FALSE))){
        getLogSupplier()->send(new Log("Gstreamer init fail", time(NULL), "g_main_loop_new fail", getLogSupplier()));
        return false;

    }
    getLogSupplier()->send(new Log("MainLoop initialized", time(NULL), "-", getLogSupplier()));
    /*Initialize Pipeline*/
    if(!(pipeline=gst_pipeline_new("AlanDefaultRTSPClientSubSystem"))){
        getLogSupplier()->send(new Log("Gstreamer init fail", time(NULL), "gst_pipeline_new fail", getLogSupplier()));
        return false;
    }
    getLogSupplier()->send(new Log("Pipeline initialized", time(NULL), "-", getLogSupplier()));
    /*Initialize elements*/

    if(!_utillLogHandler(_initializeFactories(),
                     GSTREAMER_FACTORIES_INIT_SUCCESS_LOG,GSTREAMER_FACTORIES_INIT_SUCCESS_DESC_LOG))return false;
    else if(!_utillLogHandler(_initializeElements(),
                     GSTREAMER_ELEMENTS_INIT_SUCCESS_LOG,GSTREAMER_ELEMENTS_INIT_SUCCESS_DESC_LOG))return false;
    else if(!_utillLogHandler(_initializeConnections(),
                     GSTREAMER_ELEMENTS_LINK_SUCCESS_LOG,GSTREAMER_ELEMENTS_LINK_SUCCESS_DESC_LOG))return false;
    else if(!_utillLogHandler(_applyProperties(),
                     GSTREAMER_APPLY_PROPERTIES_SUCCESS_LOG,GSTREAMER_APPLY_PROPERTIES_SUCCESS_DESC_LOG))return false;
    else if(!_utillLogHandler(_initializeBus(),
                     GSTREAMER_BUS_INIT_SUCCESS_LOG,GSTREAMER_BUS_INIT_SUCCESS_DESC_LOG))return false;
    else if(!_utillLogHandler(_initializePadAddedListeners(),
                     GSTREAMER_PAD_LISTENERS_INIT_SUCCESS_LOG,GSTREAMER_PAD_LISTENERS_INIT_SUCCESS_DESC_LOG))return false;
    else if(!_utillLogHandler(_initializeProbeListeners(),
                              GSTREAMER_PROBE_LISTENERS_INIT_SUCCESS_LOG,GSTREAMER_PROBE_LISTENERS_INIT_SUCCESS_DESC_LOG))return false;


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
    if(status)getLogSupplier()->send(new Log(onSuccessTitle, time(NULL), onSuccessMsg , getLogSupplier()));
    return status;
}

bool AlanDefaultRTSPClientSubsystem::_applyProperties() {
    g_object_set(G_OBJECT(gstrtspsrc_elem),"location",settings.value(ALAN_DEFAULT_RTSP_QSETTING_LOCATION).toString().toStdString().c_str());
    g_object_set(G_OBJECT(ximagessink_elem),"sync",FALSE);
    g_object_set(G_OBJECT(queue_elem),"max-size-bytes",30);
    g_object_set(G_OBJECT(queue_elem),"max-size-buffers",2);
    g_object_set(G_OBJECT(queue_elem),"max-size-time",settings.value(ALAN_DEFAULT_RTSP_QSETTING_LATENCY).toInt());
    gst_video_overlay_set_window_handle (GST_VIDEO_OVERLAY(ximagessink_elem),windowHandle);
    return true;
}

bool AlanDefaultRTSPClientSubsystem::_initializeBus() {
    return (mainBus=gst_pipeline_get_bus(GST_PIPELINE(pipeline)))&&
            (bus_handler_watch_id=gst_bus_add_watch(mainBus,generic_bus_handler,NULL));
}

bool AlanDefaultRTSPClientSubsystem::_initializePadAddedListeners() {
    rtspsrc_pad_added_signal_id=g_signal_connect(GST_ELEMENT(gstrtspsrc_elem),"pad-added",G_CALLBACK(on_pad_added_rtspsrc_listener),queue_elem);
    decodebin_pad_added_signal_id=g_signal_connect(GST_ELEMENT(decodebin_elem),"pad-added",G_CALLBACK(on_pad_added_decodebin_listener),videoconvert_elem);
    return true;
}

bool AlanDefaultRTSPClientSubsystem::_initializeProbeListeners() {
    GstPad*_temp=gst_element_get_static_pad(decodebin_elem,"sink");
    on_timestamp_export_probe_triggered_probe_id=
            gst_pad_add_probe(_temp,
                              GST_PAD_PROBE_TYPE_BUFFER,
                              (GstPadProbeCallback) on_timestamp_export_probe_triggered,
                              (void *)this,
                              NULL);
    gst_object_unref(_temp);


}


extern "C" int  trigger_new_frame(void *alanDefaultRTSPClientSubsystem_entity,unsigned long ID,unsigned long TIMESTAMP){
    DataSupplier*_ref=(reinterpret_cast<AlanDefaultRTSPClientSubsystem*>(alanDefaultRTSPClientSubsystem_entity)
            ->getDataSupplier());
    _ref->send(new Data(ID,TIMESTAMP,_ref));
    return true;
}

bool AlanDefaultRTSPClientSubsystem::de_initializeGstreamer() {


    if(!_utillLogHandler(_de__initializeProbeListeners(),
                         GSTREAMER_PROBE_LISTENERS_INIT_SUCCESS_LOG,GSTREAMER_PROBE_LISTENERS_INIT_SUCCESS_DESC_LOG))return false;
    else if(!_utillLogHandler(_de__initializePadAddedListeners(),
                              GSTREAMER_PAD_LISTENERS_INIT_SUCCESS_LOG,GSTREAMER_PAD_LISTENERS_INIT_SUCCESS_DESC_LOG))return false;
    else if(!_utillLogHandler(_de__initializeBus(),
                              GSTREAMER_BUS_INIT_SUCCESS_LOG,GSTREAMER_BUS_INIT_SUCCESS_DESC_LOG))return false;
    else if(!_utillLogHandler(_de__applyProperties(),
                              GSTREAMER_APPLY_PROPERTIES_SUCCESS_LOG,GSTREAMER_APPLY_PROPERTIES_SUCCESS_DESC_LOG))return false;
    else if(!_utillLogHandler(_de__initializeConnections(),
                              GSTREAMER_ELEMENTS_LINK_SUCCESS_LOG,GSTREAMER_ELEMENTS_LINK_SUCCESS_DESC_LOG))return false;
    else if(!_utillLogHandler(_de__initializeElements(),
                              GSTREAMER_ELEMENTS_INIT_SUCCESS_LOG,GSTREAMER_ELEMENTS_INIT_SUCCESS_DESC_LOG))return false;

    else if(!_utillLogHandler(_de__initializeFactories(),
                              GSTREAMER_FACTORIES_INIT_SUCCESS_LOG,GSTREAMER_FACTORIES_INIT_SUCCESS_DESC_LOG))return false;

    //if mainloop is running then stop , the MainLoopThread will emit the interruptedSignal and will be freed
    if(g_main_loop_is_running(mainLoop)){
        g_main_loop_quit(mainLoop);
    }
    g_main_loop_unref(mainLoop);

    getLogSupplier()->send(new Log("MainLoop destructed", time(NULL), "-", getLogSupplier()));


    gst_element_set_state(GST_ELEMENT(pipeline),GST_STATE_NULL);
    g_free(pipeline);
    /*Initialize elements*/
    return true;


}

bool AlanDefaultRTSPClientSubsystem::_de__initializeFactories() {
    return false;
}

bool AlanDefaultRTSPClientSubsystem::_de__initializeElements() {
    return false;
}

bool AlanDefaultRTSPClientSubsystem::_de__initializeConnections() {
    gst_element_unlink_many(
            gstrtspsrc_elem,
            queue_elem,
            rtph264depayloader_elem,
            decodebin_elem,
            videoconvert_elem,
            ximagessink_elem);
    gst_bin_remove_many(GST_BIN(pipeline),
                     gstrtspsrc_elem,
                     queue_elem,
                     rtph264depayloader_elem,
                     decodebin_elem,
                     videoconvert_elem,
                     ximagessink_elem,NULL);


    return true;
}

bool AlanDefaultRTSPClientSubsystem::_de__applyProperties() {
    //return everything in default state -> last updated : may 1 , 2018
    g_object_set(G_OBJECT(gstrtspsrc_elem),"location",NULL);
    g_object_set(G_OBJECT(ximagessink_elem),"sync",FALSE);
    g_object_set(G_OBJECT(queue_elem),"max-size-bytes",10485760);
    g_object_set(G_OBJECT(queue_elem),"max-size-buffers",200);
    g_object_set(G_OBJECT(queue_elem),"max-size-time",1000000000);
    gst_video_overlay_set_window_handle (GST_VIDEO_OVERLAY(ximagessink_elem),0);
}

bool AlanDefaultRTSPClientSubsystem::_de__initializeBus() {
    gst_bus_remove_watch(mainBus);
    //! do not unref the mainBus , this responsibillity is taken from destruction of pipeline !
    return true;
}

bool AlanDefaultRTSPClientSubsystem::_de__initializePadAddedListeners() {
    g_signal_handler_disconnect(GST_ELEMENT(gstrtspsrc_elem),rtspsrc_pad_added_signal_id);
    rtspsrc_pad_added_signal_id=0;
    g_signal_handler_disconnect(GST_ELEMENT(decodebin_elem),decodebin_pad_added_signal_id);
    decodebin_pad_added_signal_id=0;
    return true;
}

bool AlanDefaultRTSPClientSubsystem::_de__initializeProbeListeners() {
    GstPad*_temp=gst_element_get_static_pad(decodebin_elem,"sink");
    gst_pad_remove_probe(_temp,on_timestamp_export_probe_triggered_probe_id);
    on_timestamp_export_probe_triggered_probe_id=0;
    g_free(_temp);
    return true;

}

bool AlanDefaultRTSPClientSubsystem::_utill_gst_object_unref_many(int i, ...) {
    va_list args;
    va_start(i,args);
    GstObject*_tmp;
    for (int j = i; j >0 ; --j) {
        _tmp=va_arg(args,GstObject*);
        gst_object_unref(_tmp);
    }
    return true;
}
