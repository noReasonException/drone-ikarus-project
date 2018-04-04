//
// Created by noreasonexception on 4/2/18.
//

#ifndef IKARUS_PROJECT_LOGPANEL_H
#define IKARUS_PROJECT_LOGPANEL_H


#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "../StreamPanel.h"
#include "../../../Consumer/LogConsumer/LogConsumer.h"
#include "../../../Interfaces/LogSupplierFactory.h"

class LogPanel:public StreamPanel, public LogConsumer,public LogSupplierFactory {
public:
    LogPanel(const QString &str);

    void accept(InformationObjectSupplier *supplier, InformationObject *info) override;

    LogSupplier *createSupplier(QString supplierName) override;

    static LogPanel*getInstance(QString title);

protected:
    static LogPanel*instance;


};


#endif //IKARUS_PROJECT_LOGPANEL_H
