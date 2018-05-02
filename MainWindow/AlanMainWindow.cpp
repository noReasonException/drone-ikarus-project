//
// Created by noreasonexception on 4/1/18.
//

#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QLabel>
#include <iostream>
#include "AlanMainWindow.h"
#include "../misc/img/generic_paths.h"
#include "Panels/StreamPanel/LogPanel/LogPanel.h"
#include "../misc/generic_text/generic_dialogs.h"
#include "../InformationObject/Log/Log.h"
#include "../misc/generic_text/AlanMainWindowMisc.h"
#include "../misc/Suppliers/LogSuppliers.h"
#include "State/WindowStates/AlanTwoButtonsDialogState/AlanMultipleChoiceDialogState/AlanMultipleChoiceDialogState.h"
#include "../misc/Suppliers/OptionSuppliers.h"
#include "Panels/StreamPanel/DataPanel/DataPanel.h"
#include "../InformationObject/Data/Data.h"

/***
 * AlanMainWindowConstructor
 *
 */
AlanMainWindow::AlanMainWindow(AbstractFactory*factory):parentFactory(factory) {

    isStreaming= false;
    isReTransmitting= false;
    supplier=LogPanel::getInstance()->createSupplier(ALAN_MAIN_WINDOW_SUPPLIER);
    rtspClientOptionSupplier=factory->getRTSPSubsystem()->createSupplier(MAINWINDOW_OPTION_SUPPLIER);
    if(!genericInitializer()){
        QMessageBox::critical(this,GENERIC_INITIALIZATION_ERROR_DIALOG ERR01_DETAILS);
        closeSlot();
    }
    setMinimumWidth(maximumWidth());
    setMinimumHeight(maximumHeight());
}
/***
 * genericInitializer
 * This is the top most error-check layer,
 * Checks all the initialization processes
 * In case of error , ask the user if want to continue or terminate.
 *
 * @return true if all initialization steps where successful
 */
bool AlanMainWindow::genericInitializer() {
    return initializeMenu()     &&
           initializeToolBar()  &&
            initializeCentralWidget();
}
/***
 * Calls the protected : onGenerateMenu() and returns true if everything where successful
 * Why dont initialize directly from here?
 * well.. for better code quality , it is need to split the initialization proccess from check if
 * this is successful , if the future programmer wants to add something , just override the onGenerateMenu()
 * and the job is done , if something where wrong , then just throw an exception and everything else will
 * be managed by initializeMenu() and genericInitializer().
 * @return true if the initialization proccess where successful
 */
bool AlanMainWindow::initializeMenu() try {
    for (QMenu *tmp:*onGenerateMenu(menuBar()))
        menuBar()->addMenu(tmp);
    return true;
}catch (std::exception &e){return false;}

/***
 * Takes care the steps to initialize the menu
 * @param bar , the
 */
std::vector<QMenu*>* AlanMainWindow::onGenerateMenu(QMenuBar *bar) throw (std::exception){

    auto*retval=new std::vector<QMenu*>();
    QMenu*tmp;
    QAction *tmpAct;
    retval->push_back(tmp=new QMenu(OPTIONS_MENU_NAME));
    //This section initializes the 'Options' menu
    {
        tmp->addAction(initializeQAction(
                new QAction(RESOLUTION_ACTION_NAME),
                RESOLUTION_ICON,
                SLOT(genericActionSlot())));

        tmp->addAction(initializeQAction(
                new QAction(LATENCY_ACTION_NAME),
                LATENCY_ICON,
                SLOT(genericActionSlot())));

        tmp->addAction(initializeQAction(
                new QAction(ERROR_FILE_ACTION_NAME),
                ERROR_FILE_ICON,
                SLOT(genericActionSlot())));

        tmp->addAction(initializeQAction(
                new QAction(DATA_FILE_ACTION_NAME),
                DATA_FILE_ICON,
                SLOT(genericActionSlot())));

        tmp->addSeparator();
        tmp->addAction(initializeQAction(
                new QAction(EXIT_ACTION_NAME),
                EXIT_ICON,
                SLOT(closeSlot())));

    }
    retval->push_back(tmp=new QMenu(SOURCE_MENU_NAME));
    {

        tmp->addAction(initializeQAction(
                new QAction(DRONE_ADDR_ACTION_NAME),
                DRONE_ADDR_ICON,
                SLOT(genericActionSlot())));

        tmp->addAction(initializeQAction(
                new QAction(START_STREAMING_ACTION_NAME),
                STREAMING_ICON,
                SLOT(genericActionSlot())));

        tmp->addAction(initializeQAction(
                new QAction(STOP_STREAMING_ACTION_NAME),
                STOP_STREAMING_ICON,
                SLOT(genericActionSlot())));
    }

    retval->push_back(tmp=new QMenu(RETRANSMIT_MENU_NAME));
    {
        tmp->addAction(initializeQAction(
                new QAction(SERVER_ADDR_ACTION_NAME),
                SERVER_ADDR_ICON,
                SLOT(operationNotSupportedSlot())));

        tmp->addAction(initializeQAction(
                new QAction(START_BROADCAST_ACTION_NAME),
                BROADCAST_ICON,
                SLOT(operationNotSupportedSlot())));

        tmp->addAction(initializeQAction(
                new QAction(STOP_BROADCAST_ACTION_NAME),
                STOP_BROADCAST_ICON,
                SLOT(operationNotSupportedSlot())));
    }
    retval->push_back(tmp=new QMenu(TOOLS_MENU_NAME));
    retval->push_back(tmp=new QMenu(HELP_MENU_NAME));
    {
        tmp->addAction(initializeQAction(
                new QAction(ABOUT_ACTION_NAME),
                DRONE_ADDR_ICON, ////TODO find a About Icon
                SLOT(genericActionSlot())));
    }
    return retval;
}
/***
 * A useful utility for more elegant menu initialization , is used by onGenerateMenu
 * @param act           the QAction object to initialize
 * @param fileName      the icon filename
 * @param onClickSlot   the slot will be triggered in case of click
 * @return a fresh - initialized QAction
 * @note  use the misc/img/*ImagePaths.h files for parameter @param fileName , do not hard-copy the image paths
 *              Its ugly .
 */
QAction* AlanMainWindow::initializeQAction(QAction *act,QString fileName,const char* onClickSlot){
    if(!act)return nullptr;
    act->setIcon(QIcon(fileName));
    QObject::connect(act,SIGNAL(triggered(bool)),this,onClickSlot);
    return act;

}
/***
 * A default slot for develepoment purposes
 * //TODO remove it!
 */
void AlanMainWindow::operationNotSupportedSlot() {

    QMessageBox::warning(this,OPERATION_NOT_SUPPORTED_ERROR_DIALOG);
}

/***
 * This slot triggered in case of exit , it checks if any task is in progress and informs the user if really wants to exit ;)
 */
void AlanMainWindow::closeSlot(){
    changeStatusOfRTSPClientSubsystem(Client_STOP);//release resource

    close();
}
/***
 * A simple wrapper over onGenerateToolBar ,it checks if this function is called successfully ,
 * and informs the upper error-protection layer (the generic_initializer() in case of error
 *
 * @note why we dont initialize directly from here?
 * @see the comment section of AlanMainWindow::initializeMenu
 * @return true if everything is okay , false otherwise
 */
bool AlanMainWindow::initializeToolBar() try{

        for(QToolBar *bar:*onGenerateToolBar())addToolBar(bar);
        return true;

}catch (std::exception&e){return false;}
/***
 * onGenerateToolBar does the real job of initializing the ToolBar .
 * this can be overriden . the user only returns a vector of brand-new toolbar's ,
 * @note this function HAS NOT responsibility of toolbar insertion in Window .
 * this means that commands like...
 *                      this->addToolBar(bar)
 * ...is strictly forbidden (To maintain a elegant code)
 * @return a std::vector with Toolbars
 */
std::vector<QToolBar*>*AlanMainWindow::onGenerateToolBar() throw(std::exception) {
    QToolBar*tmp;
    QAction*tmpact;
    auto *retval=new std::vector<QToolBar*> ();
    retval->push_back(tmp=new QToolBar("MediaBar"));
    initializeQAction(tmp->addAction(START_STREAMING_ACTION_NAME),STREAMING_ICON,SLOT(genericActionSlot()));
    initializeQAction(tmp->addAction(STOP_STREAMING_ACTION_NAME),STOP_STREAMING_ICON,SLOT(genericActionSlot()));
    initializeQAction(tmp->addAction(START_BROADCAST_ACTION_NAME),BROADCAST_ICON,SLOT(genericActionSlot()));
    initializeQAction(tmp->addAction(STOP_BROADCAST_ACTION_NAME),STOP_BROADCAST_ICON,SLOT(genericActionSlot()));
    return retval;

}
/***
 * A simple wrapper over onGenerateCentralWidget ,it checks if this function is called successfully ,
 * and informs the upper error-protection layer (the generic_initializer() in case of error
 *
 * @note why we dont initialize directly from here?
 * @see the comment section of AlanMainWindow::initializeMenu
 * @return true if everything is okay , false otherwise
 *
***/
bool AlanMainWindow::initializeCentralWidget()  try{
        setCentralWidget(onGenerateCentralWidget());
        return true;

}catch (std::exception&e){return false;}
/***
 * onGenerateCentralWidget() does the real job of initializing and returning a QWidget
 * destined to be centralWidget().
 * @return a new QWidget destined to be centralWidget
 *  * @note this function HAS NOT responsibility of assigning the QWidget as CentralWidget.
 * this means that commands like...
 *                      this->setCentralWidget(...->)
 * ...is strictly forbidden (To maintain a elegant code)
 */
QWidget* AlanMainWindow::onGenerateCentralWidget() throw(std::exception){
    QDialog*retval=new QDialog();
    setCentralWidget(retval);
    QGridLayout *main_lay;
    retval->setLayout(main_lay=new QGridLayout());

    try{
        main_lay->addWidget(onGenerateLeftLayout(),0,0,1,4);
        main_lay->addWidget(onGenerateVideoArea(),0,7,1,6);
        main_lay->addWidget(onGenerateRightLayout(),0,14,1,4);
    }catch(std::exception&e){throw e;}

    return retval;

}
/***
 * onGenerateLeftLayout() does the real job of initializing and returning a QWidget
 * destined to be aligned as Qt::AlignLeft in CentralWidget().
 * @return a new QWidget destined to added in CentralWidget()
 *  * @note this function HAS NOT responsibility of assigning the QWidget inside CentralWidget.
 * this means that commands like...
 *                      layout->addWidget(...,...,Qt::AlignLeft)
 * ...is strictly forbidden (To maintain a elegant code and avoid bugs)
 */
QWidget *AlanMainWindow::onGenerateLeftLayout() throw (std::exception){
    return DataPanel::getInstance();
}
/***
 * onGenerateVideoArea() does the real job of initializing and returning a QWidget
 * destined to be aligned as Qt::AlignCenter in CentralWidget().
 * @return a new QWidget destined to added in CentralWidget()
 *  * @note this function HAS NOT responsibility of assigning the QWidget inside CentralWidget.
 * this means that commands like...
 *                      layout->addWidget(...,...,Qt::AlignCenter)
 * ...is strictly forbidden (To maintain a elegant code and avoid bugs)
 */
QWidget *AlanMainWindow::onGenerateVideoArea() throw (std::exception){
    QListView *lbl= new QListView;
    lbl->setStyleSheet("QLabel { background:black;width:150%;height:150% } ");
    setWindowHandlerOfRTSPClientSubsystem(lbl->winId());
    return lbl;
}
/***
 * onGenerateRightLayout() does the real job of initializing and returning a QWidget
 * destined to be aligned as Qt::AlignRight in CentralWidget().
 * @return a new QWidget destined to added in CentralWidget()
 *  * @note this function HAS NOT responsibility of assigning the QWidget inside CentralWidget.
 * this means that commands like...
 *                      layout->addWidget(...,...,Qt::AlignRight)
 * ...is strictly forbidden (To maintain a elegant code and avoid bugs)
 */
QWidget *AlanMainWindow::onGenerateRightLayout() throw(std::exception){
    LogPanel*pnl=LogPanel::getInstance();
    return pnl;
}

void AlanMainWindow::genericActionSlot() {
    QDialog * preparedDialog = nullptr;
    std::string str=reinterpret_cast<QAction*>(QObject::sender())->text().toStdString();
    const char *cstr=str.c_str();
    if(!strcmp(cstr,SERVER_ADDR_ACTION_NAME))preparedDialog=(parentFactory->getServerAddrDialog());
    else if(!strcmp(cstr,DRONE_ADDR_ACTION_NAME))preparedDialog=(parentFactory->getDroneAddrDialog());
    else if(!strcmp(cstr,RESOLUTION_ACTION_NAME))preparedDialog=(parentFactory->getResolutionDialog());
    else if(!strcmp(cstr,LATENCY_ACTION_NAME))preparedDialog=(parentFactory->getLatencyDialog());
    else if(!strcmp(cstr,ABOUT_ACTION_NAME))preparedDialog=(parentFactory->getAboutDialog());

    if(preparedDialog)preparedDialog->show();
    else {
        if(!strcmp(cstr,START_STREAMING_ACTION_NAME)){
            changeStatusOfRTSPClientSubsystem(ClientStatus::Client_START);
            changeStatusOfRTSPClientSubsystem(ClientStatus::Client_PLAY);
        }
        else if(!strcmp(cstr,STOP_STREAMING_ACTION_NAME))changeStatusOfRTSPClientSubsystem(ClientStatus::Client_PAUSE);
        else{
            getSupplier()->send(new Log(OPERATION_NOT_FOUND_TITLE_LOG,time(nullptr),OPERATION_NOT_FOUND_DESC_LOG,getSupplier()));
            operationNotSupportedSlot();

        }


    }

}

LogSupplier *AlanMainWindow::getSupplier() const {
    return supplier;
}

void AlanMainWindow::changeStatusOfRTSPClientSubsystem(ClientStatus status) {
    getRtspClientOptionSupplier()->send(new class ClientStatusOption(
            status,
            time(NULL),
            getRtspClientOptionSupplier()
    ));

}

OptionSupplier *AlanMainWindow::getRtspClientOptionSupplier() const {
    return rtspClientOptionSupplier;
}

void AlanMainWindow::setWindowHandlerOfRTSPClientSubsystem(const WId handle) {
    getRtspClientOptionSupplier()->send(new class WindowHandleOption(
            handle,
            time(NULL),
            getRtspClientOptionSupplier()));

}
