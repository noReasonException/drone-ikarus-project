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

AlanDefaultRTSPClientSubsystem::AlanDefaultRTSPClientSubsystem() : currentStatus(Client_NONE) {
    mainLoopThread=new class MainLoopThread();

}

AlanDefaultRTSPClientSubsystem::~AlanDefaultRTSPClientSubsystem() {
    if(!de_initializeGstreamer()){
        getLogSupplier()->send(
                new Log(GSTREAMER_DESTRUCT_FAIL_LOG,
                time(NULL),
                GSTREAMER_DESTRUCT_FAIL_DESC_LOG,getLogSupplier()));
    }

}
/****
* onLatencySettingChangedHandler
* It is called automatically by parent class , in case of LatencyOption* request in .accept() base class method
* @param obj the LatencyOption* object
* @note IMPORTANT :
*              This method is not responsible for deleting the @param obj pointer . base class has this responsibillity
* TODO : maybe the handler will run in a different thread instead? ^^ think about pros/cos
* @return true in case of successfully handled!
*/
bool AlanDefaultRTSPClientSubsystem::onLatencySettingChangedHandler(class LatencyOption *option) {
    if(_utill_isNullThenLog(option,
                            INVALID_ARG_LATENCYOPTION_EXPECTED_LOG))return false;
    settings.setValue(ALAN_DEFAULT_RTSP_QSETTING_LATENCY,option->getLatency());
    return true;
}
/****
* onResolutionSettingChangedHandler
* It is called automatically by parent class , in case of ResolutionOption* request in .accept() base class method
* @param obj the ResolutionOption* object
* @note IMPORTANT :
*              This method is not responsible for deleting the @param obj pointer . base class has this responsibillity
* TODO : maybe the handler will run in a different thread instead? ^^ think about pros/cos
* @return true in case of successfully handled!
*/
bool AlanDefaultRTSPClientSubsystem::onResolutionSettingChangedHandler(class ResolutionOption *obj) {
    if(_utill_isNullThenLog(obj,
                            INVALID_ARG_RESOLUTIONOPTION_EXPECTED_LOG))return false;
    settings.setValue(ALAN_DEFAULT_RTSP_QSETTING_RESOLUTION_WIDTH,obj->getWidth());
    settings.setValue(ALAN_DEFAULT_RTSP_QSETTING_RESOLUTION_HEIGHT,obj->getHeight());
    return true;
}
/****
* onClientStatusSettingChangedHandler
* It is called automatically by parent class , in case of ClientStatusOption* request in .accept() base class method
* @param obj the ClientStatusOption* object
* @note IMPORTANT :
*              This method is not responsible for deleting the @param obj pointer . base class has this responsibillity
* TODO : maybe the handler will run in a different thread instead? ^^ think about pros/cos
* @return true in case of successfully handled!
*/
bool AlanDefaultRTSPClientSubsystem::onClientStatusSettingChangedHandler(class ClientStatusOption *option) {
    if(_utill_isNullThenLog(option,
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
/****
* onWindowHandlerSettingChangedHandler
* It is called automatically by parent class , in case of WindowHandleOption* request in .accept() base class method
* @param obj the WindowHandleOption* object
* @note IMPORTANT :
*              This method is not responsible for deleting the @param obj pointer . base class has this responsibillity
* TODO : maybe the handler will run in a different thread instead? ^^ think about pros/cos
* @return true in case of successfully handled!
*/
bool AlanDefaultRTSPClientSubsystem::onWindowHandlerSettingChangedHandler(class WindowHandleOption *obj) {
    if(_utill_isNullThenLog(obj,
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
    windowHandle=obj->getWindowHanle();
    return true;
}
/****
 * onLocationSettingChangedHandler
 * It is called automatically by parent class , in case of LocationOption* request in .accept() base class method
 * @param obj the LocationOption* object
 * @note IMPORTANT :
 *              This method is not responsible for deleting the @param obj pointer . base class has this responsibillity
 * //TODO : maybe the handler will run in a different thread instead? ^^ think about pros/cos
 * @return true in case of successfully handled!
*/
bool AlanDefaultRTSPClientSubsystem::onLocationSettingChangedHandler(class LocationOption *obj) {
    if(_utill_isNullThenLog(obj,
                            INVALID_ARG_LOCATION_EXPECTED_LOG))return false;
    settings.setValue(ALAN_DEFAULT_RTSP_QSETTING_LOCATION,obj->getIpLocation());
    return true;


}
/****
 * _utill_isNullThenLog
 * simple utillity method to log a specific error if the @param ptr is NULL
 * @note why not nullptr? , to be backwards compatible with C 89 :)
 * @param ptr  the parameter to check
 * @param onErrorMessage in case of @param ptr==null , the text will be logged
 * @return true if ptr==NULL
 */
bool AlanDefaultRTSPClientSubsystem::_utill_isNullThenLog(void *ptr,
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



/***
 * callProperStatusHandler()
 * is called automatically from AbstractRTSPClientSubsystem in case of any ClientStatusOption* request from GUI-Space
 * it is responsible to call the proper handler for each Request
 * //TODO :what about dynamic handlers (Lambdas) sometime in future? ^^
 *
 * @note it is invalid-call safe .
 *
 */
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
/***
 * onStartStatusRequest
 * is called automatically from AbstractRTSPClientSubsystem in case of START request from GUI-Space
 * after START request , every pointer is initialized , but the main GMainLoop object is not running,
 * also the main pipeline is set to GST_STATE_PAUSED
 * if you need to start , you just need to send the PLAY request using OptionSupplier :)
 * @return true on success! , in case of returning false , you need to log the reason of fail . in case of success .
 * you have no responsibillity to log anything! it is done automatically from parent class
 *
 * @note it is Status-Invalid safe .
 *
 */
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
/***
 * onPlayStatusRequest
 * is called automatically from AbstractRTSPClientSubsystem in case of PAUSE request from GUI-Space
 * after PAUSE request , every pointer is still valid , but the main GMainLoop object is not running,
 * also the main pipeline is set to GST_STATE_PAUSED
 * if you need to re-start , you just need to send the PLAY request using OptionSupplier :)
 * @return true on success! , in case of returning false , you need to log the reason of fail . in case of success .
 * you have no responsibillity to log anything! it is done automatically from parent class
 *
 * @note it is Status-Invalid safe : that means that if you be in START state (only initialized but not ever run ,
 * that this call will simply return false
 *
 */
bool AlanDefaultRTSPClientSubsystem::onPlayStatusRequest() {
    if(currentStatus!=Client_START&&currentStatus!=Client_PAUSE) {
        return false;
    }
    mainLoopThread->setLoop(mainLoop)->start();
    gst_element_set_state(GST_ELEMENT(pipeline),GST_STATE_PLAYING);
    //g_main_loop_run(mainLoop);

    return true;
}
/***
 * onPauseStatusRequest
 * is called automatically from AbstractRTSPClientSubsystem in case of PAUSE request from GUI-Space
 * after PAUSE request , every pointer is still valid , but the main GMainLoop object is not running,
 * also the main pipeline is set to GST_STATE_PAUSED
 * if you need to re-start , you just need to send the PLAY request using OptionSupplier :)
 * @return true on success! , in case of returning false , you need to log the reason of fail . in case of success .
 * you have no responsibillity to log anything! it is done automatically from parent class
 *
 * @note it is Status-Invalid safe : that means that if you be in START state (only initialized but not ever run ,
 * that this call will simply return false
 *
 */
bool AlanDefaultRTSPClientSubsystem::onPauseStatusRequest() {

    if(currentStatus!=Client_PLAY)
        return false;
    gst_element_set_state(pipeline,GST_STATE_PAUSED);
    g_main_loop_quit(mainLoop);
    return true;
}
/***
 * onStopStatusRequest
 * is called automatically from AbstractRTSPClientSubsystem in case of STOP request from GUI-Space
 * after Stop request , every pointer is invalid , and it is expected to terminate
 * in case of future add on , remember that you need to re-call _initializeGstreamer() to avoid segmentation faults!
 * @return true on success! , in case of returning false , you need to log the reason of fail . in case of success .
 * you have no responsibillity to log anything! it is done automatically from parent class
 *
 */
bool AlanDefaultRTSPClientSubsystem::onStopStatusRequest() {
    de_initializeGstreamer();
    return true;
}
/****
 * initializeGstreamer
 * this method initialize the Gstreamer Subsystem , always use as pair with _de_initializeGsteamer to avoid memory leaks!
 * @return true on success!
 */
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

    isGstreamerSubsystemInitialized=true;
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
/****
 * _initializeElements
 * this member initializes all Gstreamer Elements
 * @note we assume that the member _initializeFactories is called first
 * to initialize the factories
 * @see ./utill.c for further info about generic_initializer
 * @return true on succress
 */
bool AlanDefaultRTSPClientSubsystem::_initializeElements() {
    return(generic_initializer((GIN_FREE_STRING_AFTER | GIN_INITIALIZE_TYPE_ELEMENT), 6,
                             gstrtspsrc_fact, &gstrtspsrc_elem, g_strdup("rtsp-src"),
                             queue_fact,&queue_elem,g_strdup("buffer-queue-eleme"),
                             rtph264depayloader_fact,&rtph264depayloader_elem,g_strdup("depay-elem"),
                             decodebin_fact,&decodebin_elem,g_strdup("decodebin-element"),
                             videoconvert_fact,&videoconvert_elem,g_strdup("videoconvert-element"),
                             ximagesink_fact,&ximagessink_elem,g_strdup("ximagesink-elem")));
}
/****
 * _initializeConnections
 * this member connects the static-pad part of Gstreamer pipeline elements
 * @note we assume that members _initializeElements() has called first
 * @return true on success
 */
bool AlanDefaultRTSPClientSubsystem::_initializeConnections() {
    gst_bin_add_many(GST_BIN(pipeline),
                     gstrtspsrc_elem,           ///packets from network under RTSP
                     queue_elem,                ///Buffer
                     rtph264depayloader_elem,         ///depayloader to data
                     decodebin_elem,            ///convert h264 to video
                     videoconvert_elem,         ///raw video
                     ximagessink_elem,NULL);  ///screen
    return gst_element_link_many(queue_elem,
                    rtph264depayloader_elem,
                    decodebin_elem,NULL)&&
                                            ///decodebin -> videoconvert connection happens on on-pad event listener
                    gst_element_link(
                     videoconvert_elem,
                     ximagessink_elem);
}

/***
 * _applyProperties
 * this method sets the gstreamer elements members.
 * @note we assume that _initializeConnections() has been called first
 * @return true on success
 */
bool AlanDefaultRTSPClientSubsystem::_applyProperties() {
    g_object_set(G_OBJECT(gstrtspsrc_elem),"location",settings.value(ALAN_DEFAULT_RTSP_QSETTING_LOCATION).toString().toStdString().c_str());
    g_object_set(G_OBJECT(ximagessink_elem),"sync",FALSE);
    g_object_set(G_OBJECT(queue_elem),"max-size-bytes",30);
    g_object_set(G_OBJECT(queue_elem),"max-size-buffers",2);
    g_object_set(G_OBJECT(queue_elem),"max-size-time",settings.value(ALAN_DEFAULT_RTSP_QSETTING_LATENCY).toInt());
    gst_video_overlay_set_window_handle (GST_VIDEO_OVERLAY(ximagessink_elem),windowHandle);
    return true;
}
/****
 * _initializeBus()
 * this method submits the generic bus handler on main pipeline of gstreamer
 * @return true
 */
bool AlanDefaultRTSPClientSubsystem::_initializeBus() {
    return (mainBus=gst_pipeline_get_bus(GST_PIPELINE(pipeline)))&&
            (gst_bus_add_watch(mainBus,generic_bus_handler,NULL));
}
/****\
 * _initializePadAddedListeners
 * this method submits the handlers on signal "pad-added" on elements
 *  1) rtspsrc
 *  2) decodebin
 * this handlers will help the pipeline to correctly linked its elements .
 * @note we assume that _initializeConnections() has been called first
 * @return true on success
 */
bool AlanDefaultRTSPClientSubsystem::_initializePadAddedListeners() {
    rtspsrc_pad_added_signal_id=g_signal_connect(GST_ELEMENT(gstrtspsrc_elem),"pad-added",G_CALLBACK(on_pad_added_rtspsrc_listener),queue_elem);
    decodebin_pad_added_signal_id=g_signal_connect(GST_ELEMENT(decodebin_elem),"pad-added",G_CALLBACK(on_pad_added_decodebin_listener),videoconvert_elem);
    return true;
}
/****
 * _initializeProbeListeners ()
 * this method submits the Gstreamer Probe Handler on decodebin element , this handler is used to
 * extract the ID and the TIMESTAMP of every frame as buffer passed in stream
 * @note we assume that _initializeConnections() has been called first
 * @return true !
 */
bool AlanDefaultRTSPClientSubsystem::_initializeProbeListeners() {
    GstPad*_temp=gst_element_get_static_pad(decodebin_elem,"sink");
    on_timestamp_export_probe_triggered_probe_id=
            gst_pad_add_probe(_temp,
                              GST_PAD_PROBE_TYPE_BUFFER,
                              (GstPadProbeCallback) on_timestamp_export_probe_triggered,
                              (void *)this,
                              NULL);
    gst_object_unref(_temp);
    return true;


}

/***
 * trigger_new_frame
 * this C API function will called from gstreamer's probe when a new frame is arrived
 * @note we assume that _initializeGstreamer() has been called first
 * returns true if the call succeded and the frame information is stored !
 */
extern "C" int  trigger_new_frame(void *alanDefaultRTSPClientSubsystem_entity,unsigned long ID,unsigned long TIMESTAMP){
    DataSupplier*_ref=(reinterpret_cast<AlanDefaultRTSPClientSubsystem*>(alanDefaultRTSPClientSubsystem_entity)
            ->getDataSupplier());
    _ref->send(new Data(ID,TIMESTAMP,_ref));
    return true;
}
/*****
 * de_initializeGstreamer() ,reverse actions of initializeGstreamer() , free all pointers and destructs all Gstreamer
 * Subsystem , use it only in destructor! .
 * @return true if the destruction sequence is ok!
 */
bool AlanDefaultRTSPClientSubsystem::de_initializeGstreamer() {
    if(!isGstreamerSubsystemInitialized)
        return true;
    //if mainloop is running then stop , the MainLoopThread will emit the interruptedSignal and will be freed
    g_main_loop_quit(mainLoop);


    gst_element_set_state(GST_ELEMENT(pipeline),GST_STATE_NULL);


    if(!_utillLogHandler(_de__initializeProbeListeners(),
                         GSTREAMER_PROBE_LISTENERS_DESCRUCT_SUCCESS_LOG,
                         GSTREAMER_PROBE_LISTENERS_DESCRUCT_SUCCESS_DESC_LOG))return false;
   else if(!_utillLogHandler(_de__initializePadAddedListeners(),
                              GSTREAMER_PAD_LISTENERS_DESCRUCT_SUCCESS_LOG,
                              GSTREAMER_PAD_LISTENERS_DESCRUCT_SUCCESS_DESC_LOG))return false;
    else if(!_utillLogHandler(_de__initializeBus(),
                              GSTREAMER_BUS_DESCRUCT_SUCCESS_LOG,
                              GSTREAMER_BUS_DESCRUCT_SUCCESS_DESC_LOG))return false;
    else if(!_utillLogHandler(_de__applyProperties(),
                              GSTREAMER_APPLY_PROPERTIES_DESCRUCT_SUCCESS_LOG,
                              GSTREAMER_APPLY_PROPERTIES_DESCRUCT_SUCCESS_DESC_LOG))return false;
    else if(!_utillLogHandler(_de__initializeConnections(),
                              GSTREAMER_ELEMENTS_LINK_DESCRUCT_SUCCESS_LOG,
                              GSTREAMER_ELEMENTS_LINK_DESCRUCT_SUCCESS_DESC_LOG))return false;
    else if(!_utillLogHandler(_de__initializeElements(),
                              GSTREAMER_ELEMENTS_DESCRUCT_SUCCESS_LOG,
                              GSTREAMER_ELEMENTS_DESCRUCT_SUCCESS_DESC_LOG))return false;

    else if(!_utillLogHandler(_de__initializeFactories(),
                              GSTREAMER_FACTORIES_DESCRUCT_SUCCESS_LOG,
                              GSTREAMER_FACTORIES_DESCRUCT_SUCCESS_DESC_LOG))return false;
    g_main_loop_unref(mainLoop);
    gst_object_unref(pipeline);


    return true;


}
/**
 * A big note here...
 * Every initialization step has his reverse step of destruction ,
 * some initialization steps assume that other initialization steps has been completed before
 * the same principle goes here!
 */
/***
 * _de__initializeFactories() , reverse actions of initializeFactories()
 *
 * this method unrefs every previous used Gstreamer factory.from now on ,every member inside "Factories:" section
 * will contain INVALID pointers!(See AlanDefaultRTSPClient.h , Section "Factories")
 * @return
 */
bool AlanDefaultRTSPClientSubsystem::_de__initializeFactories() {
    return _utill_gst_object_unref_many(6,gstrtspsrc_fact,
                                 queue_fact,
                                 rtph264depayloader_fact,
                                 decodebin_fact,
                                 videoconvert_fact,
                                 ximagesink_fact);

}
/****
 * _de__initializeElements ,reverse actions of initializeElements()
 * this method unrefs every previous used Gstreamer element.from now on , every member inside "Elements:" section
 * will contain INVALID pointers!(See AlanDefaultRTSPClient.h , Section "Elements")
 * @return true if everything went well
 */
bool AlanDefaultRTSPClientSubsystem::_de__initializeElements() {
    _utill_gst_object_unref_many(6,gstrtspsrc_elem,
                                 queue_elem,
                                 rtph264depayloader_elem,
                                 decodebin_elem,
                                 videoconvert_elem,
                                 ximagessink_elem);
    return true;
}
/****
 * _de__initializeConnections ,reverse actions of initializeConnections()
 * This method , unlinks everything , and removes all elements inside pipeline
 * @return true if everything is ok!
 */
bool AlanDefaultRTSPClientSubsystem::_de__initializeConnections() {
    gst_element_unlink_many(
            gstrtspsrc_elem,
            queue_elem,
            rtph264depayloader_elem,
            decodebin_elem,
            videoconvert_elem,
            ximagessink_elem,NULL);
    gst_bin_remove_many(GST_BIN(pipeline),
                     gstrtspsrc_elem,
                     queue_elem,
                     rtph264depayloader_elem,
                     decodebin_elem,
                     videoconvert_elem,
                     ximagessink_elem,NULL);

    return true;
}
/****
 * _de__applyProperties , reverse actions of applyProperties()
 * Return every changed property to default values
 * last updated : may 1 , 2018
 * @return true if everything ok!
 */
bool AlanDefaultRTSPClientSubsystem::_de__applyProperties() {
    //return everything in default state -> last updated : may 1 , 2018
    g_object_set(G_OBJECT(gstrtspsrc_elem),"location",NULL);
    g_object_set(G_OBJECT(ximagessink_elem),"sync",FALSE);
    g_object_set(G_OBJECT(queue_elem),"max-size-bytes",10485760);
    g_object_set(G_OBJECT(queue_elem),"max-size-buffers",200);
    g_object_set(G_OBJECT(queue_elem),"max-size-time",1000000000);
    gst_video_overlay_set_window_handle (GST_VIDEO_OVERLAY(ximagessink_elem),0);
    return true;
}
/***
 * _de__initializeBus , reverse actions of initializeBus()
 * this utill will remove the bus message handler
 * @return true if everything went well
 */
bool AlanDefaultRTSPClientSubsystem::_de__initializeBus() {
    gst_bus_remove_watch(mainBus);
    //! do not unref the mainBus , this responsibillity is taken from destruction of pipeline !
    return true;
}
/****
 * _de__initializePadAddedListeners , reverse actions of initializePadAddedListeners()
 * Remove the Pad-Added handlers from rtspsrc and decodebin elements
 * @return true if everything went well
 */
bool AlanDefaultRTSPClientSubsystem::_de__initializePadAddedListeners() {
    g_signal_handler_disconnect(GST_ELEMENT(gstrtspsrc_elem),rtspsrc_pad_added_signal_id);
    rtspsrc_pad_added_signal_id=0;
    g_signal_handler_disconnect(GST_ELEMENT(decodebin_elem),decodebin_pad_added_signal_id);
    decodebin_pad_added_signal_id=0;
    return true;
}
/****
 * _de_initializeProbeListeners , reverse actions of initializeProbeListebers()
 * Remove the Probe listener on decodebin elenemt , this Probe is used to extract the frame number.
 * @return true if everything ok!
 */
bool AlanDefaultRTSPClientSubsystem::_de__initializeProbeListeners() {
    GstPad*_temp=gst_element_get_static_pad(decodebin_elem,"sink");
    gst_pad_remove_probe(_temp,on_timestamp_export_probe_triggered_probe_id);
    on_timestamp_export_probe_triggered_probe_id=0;
    gst_object_unref(_temp);
    return true;

}
/***
 * _utill_gst_object_unref_many
 * A simple utillity tool for mass-object unreferensing
 * @param i the number of varargs
 * @param ... the Objects of type GObject*
 * @return true if everything went well
 */
bool AlanDefaultRTSPClientSubsystem::_utill_gst_object_unref_many(int i, ...) {
    va_list args;
    va_start(args,i);
    GstObject*_tmp;
    for (int j = i; j >0 ; --j) {
        _tmp=va_arg(args,GstObject*);
        gst_object_unref(_tmp);
    }
    return true;
}
/****
 * _utillLogHandler
 * This utiil submits the appropiate log in case of success initialization step.
 * @param status                the _* member (belong to initialization proccess) result
 * @param onSuccessTitle        the success title log
 * @param onSuccessMsg          the success describe log
 * @return                      the @param status value
 */
bool AlanDefaultRTSPClientSubsystem::_utillLogHandler(bool status, const QString &onSuccessTitle, const QString &onSuccessMsg) {
    if(status)getLogSupplier()->send(new Log(onSuccessTitle, time(NULL), onSuccessMsg , getLogSupplier()));
    return status;
}