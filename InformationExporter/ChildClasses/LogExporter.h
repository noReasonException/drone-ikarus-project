//
// Created by noreasonexception on 5/3/18.
//

#ifndef IKARUS_PROJECT_LOGEXPORTER_H
#define IKARUS_PROJECT_LOGEXPORTER_H


#include "../InformationExporter.h"

class LogExporter : public InformationExporter{
public:
    LogExporter();

public:
    void accept(InformationObjectSupplier *supplier, InformationObject *info) override;
};


#endif //IKARUS_PROJECT_LOGEXPORTER_H
