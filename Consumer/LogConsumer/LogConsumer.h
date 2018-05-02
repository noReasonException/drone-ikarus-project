//
// Created by noreasonexception on 4/4/18.
//

#ifndef IKARUS_PROJECT_LOGCONSUMER_H
#define IKARUS_PROJECT_LOGCONSUMER_H


#include <QArgument>
#include "../../Supplier/InformationObjectSupplier.h"
#include "../../InformationObject/InformationObject.h"
#include "../InformationObjectConsumer.h"
/****
 * LogConsumer class
 * this interface (wannabe , but...c++ :P ) is derived by every class that want to consume
 * Log* objects . As an example for this , LogPanel is an LogConsumer class , the
 * RTSP Subsystem sends Log* objects filled with information about initialization procces through an LogSupplier
 */
class LogConsumer: public InformationObjectConsumer {
public:
    void accept(InformationObjectSupplier *supplier, InformationObject *info) override=0;
};


#endif //IKARUS_PROJECT_LOGCONSUMER_H
