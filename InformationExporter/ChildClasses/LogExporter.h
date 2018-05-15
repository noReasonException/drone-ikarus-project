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

/*****
 * class LogExporter
 * this class has the responsibility to export the Log Object to files
 * this class is InformationObjectConsumer , and it accepts the following object types
 *          1) Log*                 -> and exports this object to the selected file
 *          2) LocationOption*      -> to define the file to export
 * @note Because of circular dependency problem , The LogExporter class is not allowed (temporarily) to have LogSupplier
 * //TODO fix using D.I
 *
 */
class LogExporter : public InformationExporter{
public:
    LogExporter();
    void accept(InformationObjectSupplier *supplier, InformationObject *info) override;
    static LogExporter*getInstance();
    static LogExporter*ptr;



protected:
    bool acceptLog(InformationObjectSupplier*supplier,Log*data);
    bool acceptOption(InformationObjectSupplier*supplier,Option*data);
    bool addMeta(int flags, QString source,QString type,QString desc, unsigned long timestamp);

private:
    bool hasSetTheFileLocation= false;
};


#endif //IKARUS_PROJECT_LOGEXPORTER_H
