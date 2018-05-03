//
// Created by noreasonexception on 5/3/18.
//

#ifndef IKARUS_PROJECT_LOGEXPORTER_H
#define IKARUS_PROJECT_LOGEXPORTER_H


#include "../InformationExporter.h"
#include "../../InformationObject/Log/Log.h"
#include "../../InformationObject/Option/Option.h"
#include <iostream>
#include <fstream>
#define LOG_EXPORTER_QSETTINGS_PREFIX          "LOGEXPORTER/"
#define LOG_EXPORTER_QSETTINGS_FILE_LOCATION   "FILELOCATION/"
#define LOG_EXPORTER_DEFAULT_FILE_LOCATION     "log.txt"
//TODO: Move LogExporter and DataExporter common functionality in common parent class
class LogExporter : public InformationExporter{
public:
    LogExporter();
    void accept(InformationObjectSupplier *supplier, InformationObject *info) override;
    static LogExporter*getInstance();



protected:
    bool acceptLog(InformationObjectSupplier*supplier,Log*data);
    bool acceptOption(InformationObjectSupplier*supplier,Option*data);
    bool addMeta(int flags, QString source,QString type,QString desc, unsigned long timestamp);

private:
    static LogExporter*ptr;
    bool hasSetTheFileLocation= false;
};


#endif //IKARUS_PROJECT_LOGEXPORTER_H
