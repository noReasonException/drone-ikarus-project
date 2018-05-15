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
#include "InformationExporter.h"
#include "../MainWindow/Panels/StreamPanel/LogPanel/LogPanel.h"
#include "../res/Suppliers/LogSuppliers.h"

QSettings &InformationExporter::getSettings() {
    return settings;
}

InformationExporter::InformationExporter(LogSupplier*_supl) : settings(new QSettings),supplier(_supl){}

InformationObjectSupplier *InformationExporter::createSupplier(QString supplierName) {
    return new InformationObjectSupplier(supplierName,this);
}

LogSupplier *InformationExporter::getLogSupplier() const {
    return supplier;
}

InformationExporter::~InformationExporter() {
    delete supplier;
}
