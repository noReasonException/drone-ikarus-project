//
// Created by noreasonexception on 5/3/18.
//

#ifndef IKARUS_PROJECT_DATAEXPORTER_H
#define IKARUS_PROJECT_DATAEXPORTER_H


#include "../InformationExporter.h"
#include "../../InformationObject/Data/Data.h"
#include "../../InformationObject/Option/Option.h"
#include <iostream>

#define DATA_EXPORTER_QSETTINGS_PREFIX          "DATAEXPORTER/"
#define DATA_EXPORTER_QSETTINGS_FILE_LOCATION   "FILELOCATION/"
class DataExporter : public InformationExporter{
public:
    DataExporter();

public:
    void accept(InformationObjectSupplier *supplier, InformationObject *info) override;

protected:
    void acceptData(InformationObjectSupplier*supplier,Data*data);
    void acceptOption(InformationObjectSupplier*supplier,Option*data);
    void addMeta(int flags,int ID,int TIMESTAMP);

};


#endif //IKARUS_PROJECT_DATAEXPORTER_H
