//
// Created by noreasonexception on 4/4/18.
//

#ifndef IKARUS_PROJECT_INFORMATIONOBJECTCONSUMER_H
#define IKARUS_PROJECT_INFORMATIONOBJECTCONSUMER_H


#include <QObject>
#include "../MainWindow/Supplier/InformationObjectSupplier.h"
#include "../InformationObject/InformationObject.h"
class InformationObjectSupplier;
class InformationObject;
class InformationObjectConsumer {
public:
    virtual void accept(InformationObjectSupplier*supplier,InformationObject*info)=0;
};


#endif //IKARUS_PROJECT_INFORMATIONOBJECTCONSUMER_H
