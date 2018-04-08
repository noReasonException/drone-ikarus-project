//
// Created by noreasonexception on 4/8/18.
//

#ifndef IKARUS_PROJECT_LOGSUPPLIERS_H
#define IKARUS_PROJECT_LOGSUPPLIERS_H
#define  ALAN_MAIN_WINDOW_SUPPLIER "AlanMainWindowSupplier"
    ///ALAN_MAIN_WINDOW_SUPPLIER_SECTION
    /***This sections contains all log types AlanMainWindowSupplier main throw to LogPanel
     * @note if you want to add a new one , you must define the type here , for easier debug
     */
    /***
     * Operation Not found log
     * genericActionSlot() is a slot that called by all QAction's . if this slot is not recognise the caller QAction
     * then maybe a bug exists . ;)
     */
    #define OPERATION_NOT_FOUND_TITLE_LOG   "Operation Not Found"
    #define OPERATION_NOT_FOUND_DESC_LOG    "genericActionSlot() invoked by unknown QAction , A bug maybe?"
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
    #define INVALID_ARGS_IN_ACCEPT_LOG      "Invalid args in .accept()"
    #define INVALID_ARGS_IN_ACCEPT_DESC_LOG "accept() method called with InformationObject* instead of Log* Object"
#endif //IKARUS_PROJECT_LOGSUPPLIERS_H
