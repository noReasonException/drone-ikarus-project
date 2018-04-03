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
#include "../misc/img/AlanMainWindowImagePaths.h"
#include "Panels/StreamPanel/LogPanel/LogPanel.h"

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
}
/***
 * genericInitializer
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
bool AlanMainWindow::initializeMenu() {
    try{
        for(QMenu*tmp:*onGenerateMenu(menuBar()))
            menuBar()->addMenu(tmp);
        return true;
    }catch (std::exception &e){return false;}
}
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
                SLOT(operationNotSupportedSlot())));

        tmp->addAction(initializeQAction(
                new QAction(LATENCY_ACTION_NAME),
                LATENCY_ICON,
                SLOT(operationNotSupportedSlot())));

        tmp->addAction(initializeQAction(
                new QAction(ERROR_FILE_ACTION_NAME),
                ERROR_FILE_ICON,
                SLOT(operationNotSupportedSlot())));

        tmp->addAction(initializeQAction(
                new QAction(DATA_FILE_ACTION_NAME),
                DATA_FILE_ICON,
                SLOT(operationNotSupportedSlot())));

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
                SLOT(operationNotSupportedSlot())));

        tmp->addAction(initializeQAction(
                new QAction(START_STREAMING_ACTION_NAME),
                STREAMING_ICON,
                SLOT(operationNotSupportedSlot())));

        tmp->addAction(initializeQAction(
                new QAction(STOP_STREAMING_ACTION_NAME),
                STOP_STREAMING_ICON,
                SLOT(operationNotSupportedSlot())));
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
                NO_BROADCAST_ICON,
                SLOT(operationNotSupportedSlot())));
    }
    retval->push_back(tmp=new QMenu(TOOLS_MENU_NAME));
    retval->push_back(tmp=new QMenu(MISC_MENU_NAME));
    retval->push_back(tmp=new QMenu(ABOUT_MENU_NAME));

    return retval;
}
QAction* AlanMainWindow::initializeQAction(QAction *act,QString fileName,const char* onClickSlot){
    if(!act)return nullptr;
    act->setIcon(QIcon(fileName));
    QObject::connect(act,SIGNAL(triggered(bool)),this,onClickSlot);
    return act;

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
    try{
        for(QToolBar *bar:*onGenerateToolBar())addToolBar(bar);
        return true;

    }catch (std::exception&e){return false;}
}

std::vector<QToolBar*>*AlanMainWindow::onGenerateToolBar() throw(std::exception) {
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
bool AlanMainWindow::initializeCentralWidget() {
    try{
        setCentralWidget(onGenerateCentralWidget());
        return true;

    }catch (std::exception&e){return false;}

}
QWidget* AlanMainWindow::onGenerateCentralWidget() throw(std::exception){
    QDialog*retval=new QDialog();
    setCentralWidget(retval);
    QHBoxLayout *main_lay;
    retval->setLayout(main_lay=new QHBoxLayout());

    try{
        main_lay->addWidget(onGenerateLeftLayout(),0,Qt::AlignLeft);
        main_lay->addWidget(onGenerateVideoArea(),0,Qt::AlignCenter);
        main_lay->addWidget(onGenerateRightLayout(),0,Qt::AlignRight);
    }catch(std::exception&e){throw e;}

    return retval;

}

QWidget *AlanMainWindow::onGenerateLeftLayout() throw (std::exception){
    return new QLabel("Telemetry + Data Area");
}

QWidget *AlanMainWindow::onGenerateVideoArea() throw (std::exception){
    return new QLabel("Video Area");
}

QWidget *AlanMainWindow::onGenerateRightLayout() throw(std::exception){
    return new QLabel("Log Area");

}
