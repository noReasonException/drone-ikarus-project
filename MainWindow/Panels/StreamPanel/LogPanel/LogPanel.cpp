//
// Created by noreasonexception on 4/2/18.
//

#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <iostream>
#include <QtCore/QMutexLocker>
#include "LogPanel.h"
#include "../../../../misc/generic_text/generic_dialogs.h"
#include "../../../../misc/errors/AlanPanelErrors.h"
#include "LogWidget/LogWidget.h"
#include "../../../../misc/Suppliers/LogSuppliers.h"
#include "../../../../misc/generic_text/AlanMainWindowMisc.h"

LogPanel* LogPanel::instance= nullptr;

LogPanel::LogPanel() : StreamPanel(LOGS_PANEL_TITLE) {
    log=new std::vector<Log*>();
    class_locker=new QMutex;
    self_supplier=createSupplier("Log panel");
}
////Revision at : 5/4/2018 , Thread-safe accept;
///TODO , InformationObjectSupplier , not safe in case we use other class than LogSupplier , fix that
void LogPanel::accept(InformationObjectSupplier *supplier, InformationObject *info) {
    if(supplier!=self_supplier){
        QMutexLocker locker(class_locker);
    }
    Log *l= dynamic_cast<Log*>(info);
    if(!l){
        self_supplier->send(new Log(
                INVALID_ARGS_IN_ACCEPT_LOG,
                time(NULL),
                INVALID_ARGS_IN_ACCEPT_DESC_LOG,self_supplier));
        return;
    }
    log->push_back(l);
    getListView()->addItem(l->getLogType());
}



LogSupplier *LogPanel::createSupplier(QString supplierName) {
    LogSupplier*supplier=new LogSupplier(supplierName,this);
    return supplier;

}

LogPanel *LogPanel::getInstance(QString title) {
    if(LogPanel::instance)return LogPanel::instance;
    auto pnl=new LogPanel();
    if(!pnl->generic_initializer()){
        QMessageBox::warning(nullptr,GENERIC_INITIALIZATION_ERROR_DIALOG,ERR02_DETAILS);
        return nullptr;
    }
    LogPanel::instance=pnl;
    return pnl;
}
///TODO code quality refactor
void LogPanel::onDataClicked(QListWidgetItem *item)try {

    (new LogWidget(log->operator[](item->listWidget()->currentRow())))->show();

}catch (std::exception&e){std::cout<<"FALSE";}
