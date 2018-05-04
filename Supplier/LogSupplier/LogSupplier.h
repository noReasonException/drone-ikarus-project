//
// Created by noreasonexception on 4/3/18.
//

#ifndef IKARUS_PROJECT_LOGSUPPLIER_H
#define IKARUS_PROJECT_LOGSUPPLIER_H


#include "../InformationObjectSupplier.h"


/***
 * LogSupplier . Represents a class who feeds a @see LogConsumer with Data of type @see Log
 */
class LogSupplier : public InformationObjectSupplier {
public:
    LogSupplier(const QString _supplierName,InformationObjectConsumer*target);

};


#endif //IKARUS_PROJECT_LOGSUPPLIER_H
