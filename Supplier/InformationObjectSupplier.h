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
#ifndef IKARUS_PROJECT_ABSTRACTSUPPLIER_H
#define IKARUS_PROJECT_ABSTRACTSUPPLIER_H


#include <QString>
#include "../Consumer/InformationObjectConsumer.h"
#include <QWidget>

/****
 * Class InformationObjectSupplier
 * this class represents any class that Supplies with data a InformationObjectConsumer-derived class
 * this is a simple Consumer-Supplier pattern this class has a .send() method , who calls the
 * corresponding .accept() method in the defined Consumer .
 * Supplier may be any subsystem in this programm
 * Consummer may be the LogPanel , or the DataPanel , e.t.c
 *
 * @note i have use fluent interface getters-setters, because...why not!?
 */
class InformationObjectConsumer;
class InformationObject;
class InformationObjectSupplier {
public:
    InformationObjectSupplier(const QString _supplierName,InformationObjectConsumer*target) :
            supplierName(_supplierName),
            targetConsumer(target) {}

    const QString getSupplierName() const;


    InformationObjectConsumer *getTargetConsumer() const;


    InformationObjectSupplier* setSupplierName(const QString &supplierName);


    InformationObjectSupplier* setTargetConsumer(InformationObjectConsumer *targetConsumer);

    void send(InformationObject*info);
protected:

    QString supplierName;
    InformationObjectConsumer*targetConsumer;
};


#endif //IKARUS_PROJECT_ABSTRACTSUPPLIER_H
