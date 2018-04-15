//
// Created by noreasonexception on 4/8/18.
//

#ifndef IKARUS_PROJECT_LOGSUPPLIERS_H
#define IKARUS_PROJECT_LOGSUPPLIERS_H
#define  ALAN_MAIN_WINDOW_SUPPLIER                                          "AlanMainWindowSupplier"
    ///ALAN_MAIN_WINDOW_SUPPLIER_SECTION
    /***This sections contains all log types AlanMainWindowSupplier main throw to LogPanel
     * @note if you want to add a new one , you must define the type here , for easier debug
     */
    /***
     * Operation Not found log
     * genericActionSlot() is a slot that called by all QAction's . if this slot is not recognise the caller QAction
     * then maybe a bug exists . ;)
     */
    #define OPERATION_NOT_FOUND_TITLE_LOG                                   "Operation Not Found"
    #define OPERATION_NOT_FOUND_DESC_LOG                                    "genericActionSlot() invoked by unknown QAction , A bug maybe?"
#define LOG_PANEL_SUPPLIER "Log Panel"
    /***
     * LOG_PANEL_SUPPLIER_SECTION
     * This sections contains all log types than LogPanel may throw to .... himself.. :p
     *  @note if you want to add a new one , you must define the type here , for easier debug
     */
    /***
     * invalid args in .accept() log
     * .accept() method in inherited LogConsumer version of InformationObjectConsumer , takes an abstract InformationObject as parameter . but inherited code
     * assumes that is safe to downcast to Log Object . in case that you pass something else than Log Object , this Log will send in LogPanel from..himself
     *
     *
     */
    #define INVALID_ARGS_IN_ACCEPT_LOG                                          "Invalid args in .accept()"
    #define INVALID_ARGS_IN_ACCEPT_DESC_LOG                                     "accept() method called with InformationObject* instead of Log* Object"

#define ABSTRACT_RTSP_CLIENT_SUPPLIER                                           "AbstractRtspClientSupplier"

    #define INVALID_ARG_IN_ACCEPT_LOG                                           "Invalid args in .accept() call"
    #define INVALID_INFORMATION_OBJECT_PROVIDED_IN_ACCEPT_CALL_DESC_LOG         "In AbstractRTSPClientSubsystem , in .accept() call , object of type Option* excepted at arg 2 , but something else provided"
        #define UNKNOWN_DERIVED_TYPE_OF_OPTION_PROVIDED_IN_ACCEPT_CALL_DESC_LOG "Unknown object of type Option* is provided , AbstractRTSPClientSubsystem is unable to handle the request"
        #define INVALID_ARG_LATENCYOPTION_EXPECTED_LOG                          ".onLatencySettingChangedHandler() handler call , LatencyOption* object expected"
        #define INVALID_ARG_RESOLUTIONOPTION_EXPECTED_LOG                       ".onResolutionSettingChangedHandler() handler call , ResolutionOption* object expected"
        #define INVALID_ARG_CLIENTSTATUSOPTION_EXPECTED_LOG                     ".onClientStatusSettingChangedHandler() handlercall , ClientStatusOption* object expected"
        #define INVALID_ARG_WINDOWHANDLEOPTION_EXPECTED_LOG                     ".onWindowHandlerSettingChangedHandler() handler call , WindowHandleOption* object expected"
        #define INVALID_ARG_LOCATION_EXPECTED_LOG                               ".onLocationSettingChangedHandler() handler call , LocationOption* object expected"
    #define INVALID_HANDLER_CALL_LOG                                            "Invalid Handler Call"
        #define WINDOWHANDLER_ALREADY_DEFINED_DESC_LOG                          ".onWindowHandlerSettingChangedHandler() can called only once,AbstractRTSPClientSubsystem will ignore the request"
    #define UNABLE_TO_CHANGE_STATE_LOG                                          "Unable to change state"
        #define STATE_CHANGE_REQUEST_WITHOUT_WINDOWHANDLER_SET_DESC_LOG         "AbstractRTSPClientSubsystem Cant change his state because the WindowHandle is not set,request will ignored"
    #define SUCCESS_IN_OPTION_CHANGE_LOG                                        "Property changed"
        #define OPTION_CHANGED_SUCCESS_LATENCYOPTION_DESC_LOG                   ".onLatencySettingChangedHandler() success call , LatencyOption property changed"
        #define OPTION_CHANGED_SUCCESS_RESOLUTIONOPTION_DESC_LOG                ".onResolutionSettingChangedHandler() handler call , ResolutionOption property changed"
        #define OPTION_CHANGED_SUCCESS_CLIENTSTATUSOPTION_DESC_LOG              ".onClientStatusSettingChangedHandler() handlercall , ClientStatusOption property changed"
        #define OPTION_CHANGED_SUCCESS_WINDOWHANDLEOPTION_DESC_LOG              ".onWindowHandlerSettingChangedHandler() handler call , WindowHandleOption property changed"
        #define OPTION_CHANGED_SUCCESS_LOCATION_DESC_LOG                        ".onLocationSettingChangedHandler() handler call , Location property changed"
    #define ABSTRACT_RTSP_CLIENT_STATE_CHANGE_FAILURE_LOG                       "State change Failure"
        #define NONE_STATE_REQUESTED_DESC_LOG                                   "RTSP Client subsystem has received a request to change in status NONE,the request is invalid , and will be ignored"
        #define UNNKNOWN_STATE_REQUESTED_DESC_LOG                               "RTSP Client subsystem has received a request to unnknown status,the request is invalid , and will be ignored"
        #define INVALID_CURRENT_STATE_TO_SWITCH_DESC_LOG                        "RTSP Client subsystem has received a request to switch in impossible state,the request is invalid , and will be ignored"
        #define GSTREAMER_INIT_FAILED_DESC_LOG                                  "RTSP Client subsystem has failed to initialize itself"
        #define GSTREAMER_FACTORIES_INIT_ERROR_LOG          "Gstreamer:Factory init fail"
        #define GSTREAMER_ELEMENTS_INIT_ERROR_LOG           "Gstreamer:Element init fail"
    #define GSTREAMER_FACTORIES_INIT_SUCCESS_LOG            "Factories Loaded"
        #define GSTREAMER_FACTORIES_INIT_SUCCESS_DESC_LOG   "Gstreamer:All required factories loaded"

    #define GSTREAMER_ELEMENTS_INIT_SUCCESS_LOG             "Elements Loaded"
        #define GSTREAMER_ELEMENTS_INIT_SUCCESS_DESC_LOG    "Gstreamer:All required elements loaded"
    #define GSTREAMER_ELEMENTS_LINK_SUCCESS_LOG             "Elements Linked"
        #define GSTREAMER_ELEMENTS_LINK_SUCCESS_DESC_LOG    "Gstreamer:All required elements linked"
    #define GSTREAMER_APPLY_PROPERTIES_SUCCESS_LOG          "Properies applied"
        #define GSTREAMER_APPLY_PROPERTIES_SUCCESS_DESC_LOG "Gstreamer:All configured properties linked"
    #define GSTREAMER_BUS_INIT_SUCCESS_LOG                      "GstBus Initialized"
        #define GSTREAMER_BUS_INIT_SUCCESS_DESC_LOG             "The gstreamer's GstBus* object with its generic_handler is initialized"
    #define GSTREAMER_PAD_LISTENERS_INIT_SUCCESS_LOG            "Pad-added handlers init"
        #define GSTREAMER_PAD_LISTENERS_INIT_SUCCESS_DESC_LOG   "Some elements of gstreamers has initialized his handlers on \"pad-added\" event"






#endif //IKARUS_PROJECT_LOGSUPPLIERS_H
