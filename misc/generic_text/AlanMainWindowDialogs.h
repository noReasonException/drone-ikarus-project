//
// Created by noreasonexception on 4/2/18.
//

#ifndef IKARUS_PROJECT_ALANMAINWINDOWDIALOGS_H
#define IKARUS_PROJECT_ALANMAINWINDOWDIALOGS_H


//QMessageBox exposed text
#define GENERIC_INITIALIZATION_ERROR_DIALOG "Something Went wrong :( ","The initialization process failed " " please contact with developer for further information <br>"
//Every macro with lastfix *MENU_NAME is QMenu
//Every macro with lastfix *ACTION_NAME is QAction
//Menu exposed text
#define OPTIONS_MENU_NAME               "Options"
    //Options Actions text
    #define RESOLUTION_ACTION_NAME          "Resolution Settings"
    #define LATENCY_ACTION_NAME             "Latency Settings"
    #define ERROR_FILE_ACTION_NAME          "Error Save Location"
    #define DATA_FILE_ACTION_NAME           "Data Save Location"
    #define EXIT_ACTION_NAME                "Exit"
//Source exposed text
#define SOURCE_MENU_NAME        "Source"
    #define DRONE_ADDR_ACTION_NAME "Set Drone Address"
    #define START_STREAMING_ACTION_NAME "Start Streaming"
    #define STOP_STREAMING_ACTION_NAME  "Stop Streaming"

#define RETRANSMIT_MENU_NAME    "Retransmit"
#define TOOLS_MENU_NAME         "Tools"
#define MISC_MENU_NAME          "Misc"
#define ABOUT_MENU_NAME         "About"


#endif //IKARUS_PROJECT_ALANMAINWINDOWDIALOGS_H
