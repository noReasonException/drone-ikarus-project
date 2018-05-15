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
