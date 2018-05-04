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
#define DATA_EXPORTER_DEFAULT_FILE_LOCATION     "dat.txt"
//TODO: Move LogExporter and DataExporter common functionality in common parent class
/****
 * class DataExporter
 * this class has the responsibility to export the Data* Objects (meta-information per frame) into a selected file
 * this class is InformationObjectConsumer , and it accepts the following object types
 *          1) Data*                    -> and exports this object to the selected file
 *          2) LocationOption*          -> to define the file to export
*/
class DataExporter : public InformationExporter{
public:
    DataExporter();
    static DataExporter*getInstance();
    void accept(InformationObjectSupplier *supplier, InformationObject *info) override;

protected:
    bool acceptData(InformationObjectSupplier*supplier,Data*data);
    bool acceptOption(InformationObjectSupplier*supplier,Option*data);
    bool addMeta(int flags,int ID,int TIMESTAMP);

private:
    static DataExporter*ptr;
    bool hasSetTheFileLocation= false;

};


#endif //IKARUS_PROJECT_DATAEXPORTER_H
