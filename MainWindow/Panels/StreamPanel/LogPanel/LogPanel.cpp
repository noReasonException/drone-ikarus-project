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

LogPanel* LogPanel::instance= nullptr;

LogPanel::LogPanel(const QString &str) : StreamPanel(str) {
    log=new std::vector<Log*>();
    class_locker=new QMutex;
}
////Revision at : 5/4/2018 , Thread-safe accept;
void LogPanel::accept(InformationObjectSupplier *supplier, InformationObject *info) {
    QMutexLocker locker(class_locker);
    auto *l= dynamic_cast<Log*>(info);
    if(!l){
        return ;//TODO submit a log , explaining why this log cannot export
    }
    log->push_back(l);
    getListView()->addItem(supplier->getSupplierName()+" | "+l->getLogType());
}



LogSupplier *LogPanel::createSupplier(QString supplierName) {
    LogSupplier*supplier=new LogSupplier(supplierName,this);
    return supplier;

}

LogPanel *LogPanel::getInstance(QString title) {
    if(LogPanel::instance)return LogPanel::instance;
    auto pnl=new LogPanel(title);
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
