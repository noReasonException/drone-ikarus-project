//
// Created by noreasonexception on 4/1/18.
//

#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include "AlanMainWindow.h"
#include "../misc/errors/AlanMainWindowErrors.h"
#include "../misc/version.h"

AlanMainWindow::AlanMainWindow() {
    isStreaming= false;
    isReTransmitting= false;
    if(!genericInitializer()){
        QMessageBox::critical(this,"Something Went wrong :( ","The initialization process failed "
                " please contact with developer for further information <br>"
                ERR01_DETAILS);
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
    optionsMenu=bar->addMenu("Options");
    sourceMenu=bar->addMenu("Source");
    retransmitMenu=bar->addMenu("Retransmit");
    toolsMenu=bar->addMenu("Tools");
    miscMenu=bar->addMenu("Misc");
    aboutMenu=bar->addAction("About");

    //Options Menu Setup
    optionsMenu->addAction(setResolutionAction=new QAction("Resolution Setings"));
    optionsMenu->addAction(setLatencyAction=new QAction("Latency Setings"));
    optionsMenu->addAction(setErrorFile=new QAction("Error Location Settings"));
    optionsMenu->addAction(setDataFile=new QAction("Data Location Settings"));
    optionsMenu->addSeparator();
    optionsMenu->addAction(Exit=new QAction("Exit"));

    setResolutionAction->setIcon(QIcon("img/menu/resolution.png"));
    connect(setResolutionAction,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));

    setLatencyAction->setIcon(QIcon("img/menu/latency.png"));
    connect(setLatencyAction,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));

    setErrorFile->setIcon(QIcon("img/menu/errorfile.png"));
    connect(setErrorFile,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));

    setDataFile->setIcon(QIcon("img/menu/datafile.png"));
    connect(setDataFile,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));

    Exit->setIcon(QIcon("img/menu/exit.png"));
    connect(Exit,SIGNAL(triggered(bool)),this,SLOT(closeSlot()));



    //Source Menu Setup
    sourceMenu->addAction(setDroneAddress=new QAction("Set Drone Address"));

    sourceMenu->addAction(startStreaming=new QAction("Start streaming"));
    sourceMenu->addAction(stopStreaming=new QAction("Stop streaming"));

    setDroneAddress->setIcon(QIcon("img/menu/droneip.png"));
    connect(setDroneAddress,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));
    startStreaming->setIcon(QIcon("img/menu/play.png"));
    connect(startStreaming,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));
    stopStreaming->setIcon(QIcon("img/menu/stop.png"));
    connect(stopStreaming,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));




    //Retransmit Menu Setup
    retransmitMenu->addAction(setServerIp=new QAction("Set Server Address"));
    retransmitMenu->addAction(startBroadcast=new QAction("Start broadcast"));
    retransmitMenu->addAction(stopBroadcast=new QAction("Stop broadcast"));

    setServerIp->setIcon(QIcon("img/menu/location.png"));
    connect(setServerIp,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));
    startBroadcast->setIcon(QIcon("img/menu/wifi.png"));
    connect(startBroadcast,SIGNAL(triggered(bool)),this,SLOT(operationNotSupportedSlot()));
    stopBroadcast->setIcon(QIcon("img/menu/no-wifi.png"));
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

