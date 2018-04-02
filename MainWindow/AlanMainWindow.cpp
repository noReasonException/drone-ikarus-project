//
// Created by noreasonexception on 4/1/18.
//

#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include "AlanMainWindow.h"
#include "../misc/img/AlanMainWindowImagePaths.h"

/***
 * AlanMainWindowConstructor
 * Checks all the initialization processes , terminates in case of error
 */
AlanMainWindow::AlanMainWindow() {
    isStreaming= false;
    isReTransmitting= false;
    if(!genericInitializer()){
        QMessageBox::critical(this,GENERIC_INITIALIZATION_ERROR_DIALOG ERR01_DETAILS);
        closeSlot();
    }
    setMinimumHeight(300);
    setMinimumWidth(400);
    setCentralWidget(new QDialog());
}
/***
 * genericInitializer
 * @return true if all initialization steps where successful
 */
bool AlanMainWindow::genericInitializer() {
    return initializeMenu()&& initializeToolBar();
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
bool AlanMainWindow::initializeMenu() {
    try{
        onGenerateMenu(menuBar());
        return true;
    }catch (std::exception e){return false;}
}
/***
 * Takes care the steps to initialize the menu
 * @param bar , the
 */
void AlanMainWindow::onGenerateMenu(QMenuBar *bar) {
    optionsMenu=bar->addMenu(OPTIONS_MENU_NAME);
    sourceMenu=bar->addMenu(SOURCE_MENU_NAME);
    retransmitMenu=bar->addMenu(RETRANSMIT_MENU_NAME);
    toolsMenu=bar->addMenu(TOOLS_MENU_NAME);
    miscMenu=bar->addMenu(MISC_MENU_NAME);
    aboutMenu=bar->addAction(ABOUT_MENU_NAME);

    //Options Menu Setup
    optionsMenu->addAction(setResolutionAction=new QAction(RESOLUTION_ACTION_NAME));
    optionsMenu->addAction(setLatencyAction=new QAction(LATENCY_ACTION_NAME));
    optionsMenu->addAction(setErrorFile=new QAction(ERROR_FILE_ACTION_NAME));
    optionsMenu->addAction(setDataFile=new QAction(DATA_FILE_ACTION_NAME));
    optionsMenu->addSeparator();
    optionsMenu->addAction(Exit=new QAction(EXIT_ACTION_NAME));

    setResolutionAction->setIcon(QIcon( RESOLUTION_ICON ));
    connect(setResolutionAction,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));

    setLatencyAction->setIcon(QIcon(LATENCY_ICON));
    connect(setLatencyAction,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));

    setErrorFile->setIcon(QIcon(ERROR_FILE_ICON));
    connect(setErrorFile,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));

    setDataFile->setIcon(QIcon(DATA_FILE_ICON));
    connect(setDataFile,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));

    Exit->setIcon(QIcon(EXIT_ICON));
    connect(Exit,SIGNAL(triggered(bool)),this,SLOT(closeSlot()));



    //Source Menu Setup
    sourceMenu->addAction(setDroneAddress=new QAction(DRONE_ADDR_ACTION_NAME));

    sourceMenu->addAction(startStreaming=new QAction(START_STREAMING_ACTION_NAME));
    sourceMenu->addAction(stopStreaming=new QAction(STOP_STREAMING_ACTION_NAME));

    setDroneAddress->setIcon(QIcon(DRONE_ADDR_ICON));
    connect(setDroneAddress,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));
    startStreaming->setIcon(QIcon(STREAMING_ICON));
    connect(startStreaming,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));
    stopStreaming->setIcon(QIcon(STOP_STREAMING_ICON));
    connect(stopStreaming,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));




    //Retransmit Menu Setup
    retransmitMenu->addAction(setServerIp=new QAction(SERVER_ADDR_ACTION_NAME));
    retransmitMenu->addAction(startBroadcast=new QAction(START_BROADCAST_ACTION_NAME));
    retransmitMenu->addAction(stopBroadcast=new QAction(STOP_BROADCAST_ACTION_NAME));

    setServerIp->setIcon(QIcon(SERVER_ADDR_ICON));
    connect(setServerIp,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));
    startBroadcast->setIcon(QIcon(BROADCAST_ICON));
    connect(startBroadcast,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));
    stopBroadcast->setIcon(QIcon(NO_BROADCAST_ICON));
    connect(stopBroadcast,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));


}
void AlanMainWindow::operationNotSupportedSlot() {
    QMessageBox::warning(this,OPERATION_NOT_SUPPORTED_ERROR_DIALOG);
}
void AlanMainWindow::closeSlot(){
    if((isStreaming||isReTransmitting)&&QMessageBox::warning(this,"Are you sure?",
                                                          "Are you sure you want to exit in middle of operations?",QMessageBox::Ok,QMessageBox::Cancel)==QMessageBox::Cancel){
        return;
    }
    close();
}

bool AlanMainWindow::initializeToolBar() {
    for(QToolBar *bar:*onGenerateToolBar())addToolBar(bar);
    return true;
}

std::vector<QToolBar*>*AlanMainWindow::onGenerateToolBar() {
    QToolBar*tmp;
    QAction*tmpact;
    auto *retval=new std::vector<QToolBar*> ();
    retval->push_back(tmp=new QToolBar("MediaBar"));
    tmpact=tmp->addAction("Play");
    tmpact->setIcon(QIcon("img/menu/play.png"));
    tmpact=tmp->addAction("Stop");
    tmpact->setIcon(QIcon("img/menu/stop.png"));
    tmpact=tmp->addAction("BroadCast");
    tmpact->setIcon(QIcon("img/menu/wifi.png"));
    tmpact=tmp->addAction("StopBroadCast");
    tmpact->setIcon(QIcon("img/menu/no-wifi.png"));
    return retval;

}

