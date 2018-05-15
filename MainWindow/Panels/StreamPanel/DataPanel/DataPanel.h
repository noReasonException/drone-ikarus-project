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
#ifndef IKARUS_PROJECT_DATAPANEL_H
#define IKARUS_PROJECT_DATAPANEL_H
#define MAX_DATA_ON_PANEL 30 ///TODO :move to specific *.h config file

#include <QtCore/QMutex>
#include "../StreamPanel.h"
#include "../../../../Interfaces/LogSupplierFactory.h"
#include "../../../../Consumer/LogConsumer/LogConsumer.h"
#include "../../../../Interfaces/DataSupplierFactory.h"
#include "../../../../Consumer/DataConsumer/DataConsumer.h"
#include "../../../../InformationObject/Log/Log.h"

class DataPanel : public StreamPanel,
                  public DataConsumer,
                  public DataSupplierFactory {
protected:
    static DataPanel*instance;
    LogSupplier*dataPanelLogSupplier;
    InformationObjectSupplier*dataExporterSupplier;
    QMutex *accept_locker;



    DataPanel();
public:
    void accept(InformationObjectSupplier *supplier, InformationObject *info) override;
    void _prevent_SIGFAULT();
    DataSupplier *createSupplier(QString supplierName) override;

    static DataPanel*getInstance();

private:
    void onDataClicked(QListWidgetItem *item) override;

};


#endif //IKARUS_PROJECT_DATAPANEL_H
