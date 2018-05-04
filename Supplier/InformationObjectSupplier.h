//
// Created by noreasonexception on 4/3/18.
//

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
