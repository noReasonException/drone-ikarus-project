//
// Created by noreasonexception on 5/3/18.
//

#include "LogExporter.h"
#include "../../MainWindow/Panels/StreamPanel/LogPanel/LogPanel.h"
#include "../../misc/Suppliers/LogSuppliers.h"
#include "../../InformationObject/Option/ChildOptions/LocationOption.h"

LogExporter::LogExporter() : InformationExporter(LogPanel::getInstance()->createSupplier(LOG_EXPORTER_SUPPLIER)),hasSetTheFileLocation(true){
    if(!getSettings().contains(LOG_EXPORTER_QSETTINGS_PREFIX LOG_EXPORTER_QSETTINGS_FILE_LOCATION)){
        hasSetTheFileLocation= false;
        getLogSupplier()->send(new Log(
                NO_FILE_LOCATION_CONFIG_LOG_EXPORTER_FOUND_LOG,
                time(NULL),
                NO_FILE_LOCATION_CONFIG_LOG_EXPORTER_FOUND_DESC_LOG,
                getLogSupplier()));
    }
}
void LogExporter::accept(InformationObjectSupplier *supplier, InformationObject *info) {
    Log*dataptr;
    Option*optionptr;
    if ((optionptr= dynamic_cast<Option*>(info)) && acceptOption(supplier,optionptr));
    else if((dataptr= dynamic_cast<Log*>(info)) &&acceptLog(supplier,dataptr));
    else{
        getLogSupplier()->send(new Log(
                INVALID_ARG_IN_LOG_ACCEPT_LOG,
                time(NULL),
                INVALID_INFORMATION_OBJECT_PROVIDED_IN_LOGEXPORTER_ACCEPT_CALL_DESC_LOG,
                getLogSupplier()));
        return;
    }
    // delete info;
    return;
}

bool LogExporter::acceptLog(InformationObjectSupplier *supplier, Log *log) {
    static bool hasLogFileError=false;
    bool retval;
    if(!(retval=addMeta(0,log->getSource()->getSupplierName(),log->getLogType(),log->getLogDesc(),log->getTimestamp())) && !hasLogFileError){
        hasLogFileError=true;
        getLogSupplier()->send(new Log(
                FILE_ERROR_LOG_EXPORTER_LOG,
                time(NULL),
                FILE_ERROR_LOG_EXPORTER_DESC_LOG,
                getLogSupplier()));
    }
    return retval;
}

bool LogExporter::acceptOption(InformationObjectSupplier *supplier, Option *data) {
    class LocationOption *opt =dynamic_cast<LocationOption*>(data);
    if(!opt){
        getLogSupplier()->send(new Log(
                INVALID_ARG_IN_LOG_ACCEPT_LOG,
                time(NULL),
                INVALID_LOCATION_OBJECT_PROVIDED_IN_LOGEXPORTER_ACCEPT_CALL_DESC_LOG,
                getLogSupplier()));
    }


    delete opt;
    return true;

}


bool LogExporter::addMeta(int flags, QString source,QString type,QString desc, unsigned long timestamp) {

    static std::ofstream file(hasSetTheFileLocation?
                                getSettings().value(LOG_EXPORTER_QSETTINGS_PREFIX LOG_EXPORTER_QSETTINGS_FILE_LOCATION).toString().toStdString():
                                LOG_EXPORTER_DEFAULT_FILE_LOCATION);
    file.exceptions();
    if (flags) {
        file.close();
        return true;
    }
    file << "{" << source.toStdString() << "," << type.toStdString()<<","<<desc.toStdString()<<","<<timestamp << "}"<<std::endl;
    return (bool)file;
}
