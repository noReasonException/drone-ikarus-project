//
// Created by noreasonexception on 5/3/18.
//

#include <fstream>
#include "DataExporter.h"
#include "../../InformationObject/Data/Data.h"
#include "../../InformationObject/Option/Option.h"
#include "../../misc/Suppliers/LogSuppliers.h"
#include "../../InformationObject/Log/Log.h"
#include "../../MainWindow/Panels/StreamPanel/LogPanel/LogPanel.h"
#include "../../InformationObject/Option/ChildOptions/LocationOption.h"

DataExporter::DataExporter():InformationExporter(LogPanel::getInstance()->createSupplier(DATA_EXPORTER_SUPPLIER)) {
    if(!getSettings().contains(DATA_EXPORTER_QSETTINGS_PREFIX DATA_EXPORTER_QSETTINGS_FILE_LOCATION)){
        getLogSupplier()->send(new Log(
                NO_FILE_LOCATION_CONFIG_DATA_EXPORTER_FOUND_LOG,
                time(NULL),
                NO_FILE_LOCATION_CONFIG_DATA_EXPORTER_FOUND_DESC_LOG,
                getLogSupplier()));
        hasSetTheFileLocation= false;
        return ;
    }
    hasSetTheFileLocation= true;

}

void DataExporter::accept(InformationObjectSupplier *supplier, InformationObject *info) {
    Data*dataptr;
    Option*optionptr;
    if ((optionptr= dynamic_cast<Option*>(info)) && acceptOption(supplier,optionptr));
    else if((dataptr= dynamic_cast<Data*>(info)) &&acceptData(supplier,dataptr));
    else{
        getLogSupplier()->send(new Log(
                INVALID_ARG_IN_DATA_ACCEPT_LOG,
                time(NULL),
                INVALID_INFORMATION_OBJECT_PROVIDED_IN_ACCEPT_CALL_DESC_LOG,
                getLogSupplier()));
        return;
    }
   // delete info;
    return;



}

bool DataExporter::acceptData(InformationObjectSupplier *supplier, Data *data) {
    static bool hasLogFileError=false;
    bool retval;
    if(!(retval=addMeta(0,data->getID(),data->getTimestamp()) && !hasLogFileError)){
        hasLogFileError=true;
        getLogSupplier()->send(new Log(
                FILE_ERROR_DATA_EXPORTER_LOG,
                time(NULL),
                FILE_ERROR_DATA_EXPORTER_DESC_LOG,
                getLogSupplier()));

    }
    return retval;
}

bool DataExporter::acceptOption(InformationObjectSupplier *supplier, Option *data) {
    class LocationOption*option = dynamic_cast<class LocationOption*>(data);
    if(!option){
        getLogSupplier()->send(new Log(
                INVALID_ARG_IN_DATA_ACCEPT_LOG,
                time(NULL),
                INVALID_LOCATION_OBJECT_PROVIDED_IN_ACCEPT_CALL_DESC_LOG,
                getLogSupplier()));
    }
    std::cout<<option->getLocation().toStdString();
    getSettings().setValue(DATA_EXPORTER_QSETTINGS_PREFIX DATA_EXPORTER_QSETTINGS_FILE_LOCATION, option->getLocation());
    delete option;
    return true;
}

bool DataExporter::addMeta(int flags, int ID, int TIMESTAMP) {

    static std::ofstream file(hasSetTheFileLocation?
    getSettings().value(DATA_EXPORTER_QSETTINGS_PREFIX DATA_EXPORTER_QSETTINGS_FILE_LOCATION).toString().toStdString():
                        DATA_EXPORTER_DEFAULT_FILE_LOCATION);
    file.exceptions();
    if (flags) {
        file.close();
        return true;
    }
    file << "{" << ID << "," << TIMESTAMP << "}";
    return (bool)file;
}

DataExporter *DataExporter::getInstance() {
    if(!ptr){
        ptr=new DataExporter();

    }
    return ptr;
}
DataExporter*DataExporter::ptr= nullptr;

