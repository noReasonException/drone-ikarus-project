/*
 * Copyright (C) 2018 Stefanos Stefanou
 * This file is part of AlanStreamer.

    AlanStreamer is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    AlanStreamer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.


    You should have received a copy of the GNU General Public License
    along with AlanStreamer.  If not, see <http://www.gnu.org/licenses/>.

 */
#include "LogExporter.h"
#include "../../MainWindow/Panels/StreamPanel/LogPanel/LogPanel.h"
#include "../../res/Suppliers/LogSuppliers.h"
#include "../../InformationObject/Option/ChildOptions/LocationOption.h"

LogExporter::LogExporter() : InformationExporter(nullptr),
                             hasSetTheFileLocation(false){
    if(getSettings().contains(LOG_EXPORTER_QSETTINGS_PREFIX LOG_EXPORTER_QSETTINGS_FILE_LOCATION)){
        hasSetTheFileLocation=true;

    }
}
void LogExporter::accept(InformationObjectSupplier *supplier, InformationObject *info) {
    Log*dataptr;
    Option*optionptr;
    if ((optionptr= dynamic_cast<Option*>(info)) && acceptOption(supplier,optionptr));
    else if((dataptr= dynamic_cast<Log*>(info)) &&acceptLog(supplier,dataptr));
    return;
}

bool LogExporter::acceptLog(InformationObjectSupplier *supplier, Log *log) {
    return addMeta(0,log->getSource()->getSupplierName(),log->getLogType(),log->getLogDesc(),log->getTimestamp());

}

bool LogExporter::acceptOption(InformationObjectSupplier *supplier, Option *data) {
    class LocationOption *opt =dynamic_cast<class LocationOption*>(data);
    if(!opt){
        return false;
    }
    getSettings().setValue(LOG_EXPORTER_QSETTINGS_PREFIX LOG_EXPORTER_QSETTINGS_FILE_LOCATION,opt->getLocation());

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
    file.flush(); //it is expected that very few calls will be emitted , in future , consider remove per-call-flush //TODO
    return (bool)file;
}

LogExporter *LogExporter::getInstance() {
    if(LogExporter::ptr== nullptr){
        LogExporter::ptr=new LogExporter();
    }
    return LogExporter::ptr;
}
LogExporter*LogExporter::ptr= nullptr;
