//
// Created by noreasonexception on 4/2/18.
//

#include <QHBoxLayout>
#include <QLabel>
#include <QtWidgets/QMessageBox>
#include "LogPanel.h"
#include "../../../../misc/generic_text/generic_dialogs.h"
#include "../../../../misc/errors/AlanPanelErrors.h"
LogPanel* LogPanel::instance= nullptr;

LogPanel::LogPanel(const QString &str) : StreamPanel(str) {}

void LogPanel::accept(InformationObjectSupplier *supplier, InformationObject *info) {
    title=supplier->getSupplierName();
    initializeTitleArea();
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
