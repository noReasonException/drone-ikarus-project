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
#ifndef IKARUS_PROJECT_INFORMATIONEXPORTER_H
#define IKARUS_PROJECT_INFORMATIONEXPORTER_H

#include <QtCore/QSettings>
#include "../Consumer/InformationObjectConsumer.h"
#include "../Interfaces/InformationSupplierFactory.h"
#include "../Supplier/InformationObjectSupplier.h"
#include "../Supplier/LogSupplier/LogSupplier.h"

/****
 * class InformationExporter
 * This class represents a general passing information subsystem to any destination
 *
 *
 */
class InformationExporter: public InformationObjectConsumer,
                            public InformationSupplierFactory{
private:
    QSettings   settings;
    LogSupplier*supplier;
public:
    void accept(InformationObjectSupplier *supplier, InformationObject *info) override=0;

    InformationObjectSupplier *createSupplier(QString supplierName) override;

    explicit InformationExporter(LogSupplier*);
    ~InformationExporter();

protected:
    QSettings   &getSettings() ;
    LogSupplier *getLogSupplier() const;
};


#endif //IKARUS_PROJECT_INFORMATIONEXPORTER_H
