/*
 * Copyright (C) 2018 Stefanos Stefanou
 * This file is part of AlanStreamer.

    AlanStreamer is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    AlanStreamer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.


    You should have received a copy of the GNU General Public License
    along with AlanStreamer.  If not, see <http://www.gnu.org/licenses/>.

 */
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
#include "../../../../Interfaces/LogSupplierFactory.h"
#include "../../../../InformationObject/Log/Log.h"

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

    void accept(InformationObjectSupplier *supplier, InformationObject *info) override;

    LogSupplier *createSupplier(QString supplierName) override;

    static LogPanel*getInstance();

protected:
    LogPanel();

    static LogPanel*instance;
    std::vector<Log*>*log;
    LogSupplier*self_supplier;
    InformationObjectSupplier*logExporterSupplier;
    QMutex *class_locker;


};


#endif //IKARUS_PROJECT_LOGPANEL_H
