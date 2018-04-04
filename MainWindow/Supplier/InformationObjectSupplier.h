//
// Created by noreasonexception on 4/3/18.
//

#ifndef IKARUS_PROJECT_ABSTRACTSUPPLIER_H
#define IKARUS_PROJECT_ABSTRACTSUPPLIER_H


#include <QString>
#include "../Consumer/InformationObjectConsumer.h"
#include <QWidget>
class InformationObjectConsumer;
class InformationObjectSupplier :public QWidget{
    Q_OBJECT
    friend class InformationSupplierFactory;
public:
    InformationObjectSupplier(const QString &supplierName) : supplierName(supplierName) {}

    const QString &getSupplierName() const;
    InformationObjectConsumer *getTargetConsumer() const;

protected:
    InformationObjectSupplier* setSupplierName(const QString &supplierName);


    InformationObjectSupplier* setTargetConsumer(InformationObjectConsumer *targetConsumer);

    QString supplierName;
    InformationObjectConsumer*targetConsumer;
};


#endif //IKARUS_PROJECT_ABSTRACTSUPPLIER_H
