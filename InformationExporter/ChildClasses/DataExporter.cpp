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
                NO_FILE_LOCATION_CONFIG_FOUND_LOG,
                time(NULL),
                NO_FILE_LOCATION_CONFIG_FOUND_DESC_LOG,
                getLogSupplier()));
    }
}

void DataExporter::accept(InformationObjectSupplier *supplier, InformationObject *info) {
    Data*dataptr;
    Option*optionptr;
    if (optionptr= dynamic_cast<Option*>(info)) acceptOption(supplier,optionptr);
    else if(dataptr= dynamic_cast<Data*>(info)) acceptData(supplier,dataptr);
    else{
        getLogSupplier()->send(new Log(
                INVALID_ARG_IN_DATA_ACCEPT_LOG,
                time(NULL),
                INVALID_INFORMATION_OBJECT_PROVIDED_IN_ACCEPT_CALL_DESC_LOG,
                getLogSupplier()));
    }

    return;



}

void DataExporter::acceptData(InformationObjectSupplier *supplier, Data *data) {
    addMeta(0,data->getID(),data->getTimestamp());
}

void DataExporter::acceptOption(InformationObjectSupplier *supplier, Option *data) {
    class LocationOption*option = dynamic_cast<class LocationOption*>(data);
    if(!option){
        getLogSupplier()->send(new Log(
                INVALID_ARG_IN_DATA_ACCEPT_LOG,
                time(NULL),
                INVALID_LOCATION_OBJECT_PROVIDED_IN_ACCEPT_CALL_DESC_LOG,
                getLogSupplier()));
    }
    getSettings().setValue(DATA_EXPORTER_QSETTINGS_PREFIX DATA_EXPORTER_QSETTINGS_FILE_LOCATION, option->getLocation());
}

void DataExporter::addMeta(int flags, int ID, int TIMESTAMP) {
    static std::ofstream file("meta.txt");
    if (flags) {
        file.close();
        return;
    }
    file << "{" << ID << "," << TIMESTAMP << "}";
}

