//
// Created by noreasonexception on 4/1/18.
//

#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include "AlanMainWindow.h"
#include "../misc/img/AlanMainWindowImagePaths.h"

AlanMainWindow::AlanMainWindow() {
    isStreaming= false;
    isReTransmitting= false;
    if(!genericInitializer()){
        QMessageBox::critical(this,GENERIC_INITIALIZATION_ERROR_DIALOG ERR01_DETAILS);
    }
    setMinimumHeight(300);
    setMinimumWidth(400);
    setCentralWidget(new QDialog());
}

bool AlanMainWindow::genericInitializer() {
    return initializeMenu()&& initializeToolBar();
}

bool AlanMainWindow::initializeMenu() {
    onGenerateMenu(menuBar());
    return true;
}

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
    sourceMenu->addAction(setDroneAddress=new QAction("Set Drone Address"));

    sourceMenu->addAction(startStreaming=new QAction("Start streaming"));
    sourceMenu->addAction(stopStreaming=new QAction("Stop streaming"));

    setDroneAddress->setIcon(QIcon(DRONE_ADDR_ICON));
    connect(setDroneAddress,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));
    startStreaming->setIcon(QIcon(STREAMING_ICON));
    connect(startStreaming,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));
    stopStreaming->setIcon(QIcon(STOP_STREAMING_ICON));
    connect(stopStreaming,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));




    //Retransmit Menu Setup
    retransmitMenu->addAction(setServerIp=new QAction("Set Server Address"));
    retransmitMenu->addAction(startBroadcast=new QAction("Start broadcast"));
    retransmitMenu->addAction(stopBroadcast=new QAction("Stop broadcast"));

    setServerIp->setIcon(QIcon(SERVER_ADDR_ICON));
    connect(setServerIp,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));
    startBroadcast->setIcon(QIcon(BROADCAST_ICON));
    connect(startBroadcast,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));
    stopBroadcast->setIcon(QIcon(NO_BROADCAST_ICON));
    connect(stopBroadcast,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));


}
void AlanMainWindow::operationNotSupportedSlot() {
    QMessageBox::warning(this,"Operation not supported","This operation is not supported at the version " VERSION);
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

