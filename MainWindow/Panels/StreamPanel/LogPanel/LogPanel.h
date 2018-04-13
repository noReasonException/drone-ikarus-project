//
// Created by noreasonexception on 4/2/18.
//

#ifndef IKARUS_PROJECT_LOGPANEL_H
#define IKARUS_PROJECT_LOGPANEL_H


#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QMutexLocker>
#include <QMutex>
#include <QLabel>
#include "../StreamPanel.h"
#include "../../../../Consumer/LogConsumer/LogConsumer.h"
#include "../../../Interfaces/LogSupplierFactory.h"
#include "../../../InformationObject/Log/Log.h"

/****
 * class LogPanel
 * The LogPanel class is a QWidget who belongs in AlanMainWindow (Aligned Right)
 * is responsible for show logs , of any type , from any source(any subsystem of this client
 * or server)
 *
 * To submit the logs inside the LogPanel, you need a subscribed Supplier
 * the Supplier Object takes Log objects and send them in the Log Panel
 * The Procedure go as follows ...
 *
 *
 * LogSupplier*my_supplier=LogPanel::getInstance("instance")->createSupplier("TestSubsystem");
 *  [...]
 *  [...]
 * my_supplier->send(new Log(...,...,...,...));
 *
 * @note This procedure is thread-safe
 */
class LogPanel:public StreamPanel,
               public LogConsumer,
               public LogSupplierFactory {
    Q_OBJECT

    void onDataClicked(QListWidgetItem *item) override;

public:
    LogPanel(const QString &str);

    void accept(InformationObjectSupplier *supplier, InformationObject *info) override;

    LogSupplier *createSupplier(QString supplierName) override;

    static LogPanel*getInstance(QString title);

protected:
    static LogPanel*instance;
    std::vector<Log*>*log;
    LogSupplier*self_supplier;
    QMutex *class_locker;


};


#endif //IKARUS_PROJECT_LOGPANEL_H
