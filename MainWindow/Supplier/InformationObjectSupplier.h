//
// Created by noreasonexception on 4/3/18.
//

#ifndef IKARUS_PROJECT_ABSTRACTSUPPLIER_H
#define IKARUS_PROJECT_ABSTRACTSUPPLIER_H


#include <QString>
#include "../Consumer/InformationObjectConsumer.h"
#include <QWidget>
class InformationObjectConsumer;
class InformationObjectSupplier {
    friend class InformationSupplierFactory;
public:


    const QString &getSupplierName() const;
    InformationObjectConsumer *getTargetConsumer() const;


    InformationObjectSupplier* setSupplierName(const QString &supplierName);


    InformationObjectSupplier* setTargetConsumer(InformationObjectConsumer *targetConsumer);
protected:
    InformationObjectSupplier(const QString &supplierName,InformationObjectConsumer*target) :
            supplierName(supplierName),
            targetConsumer(target) {}
    QString supplierName;
    InformationObjectConsumer*targetConsumer;
};


#endif //IKARUS_PROJECT_ABSTRACTSUPPLIER_H
