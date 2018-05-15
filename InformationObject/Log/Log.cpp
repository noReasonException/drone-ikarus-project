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
#include <QString>
#include "Log.h"

Log::Log(QString type,long timestamp,QString desc,InformationObjectSupplier*source) :
        InformationObject(timestamp,source),
        logType(type),
        logDesc(desc){


}

const QString &Log::getLogType() const {
    return logType;
}

Log* Log::setLogType(const QString &logType) {
    Log::logType = logType;
    return this;
}

const QString &Log::getLogDesc() const {
    return logDesc;
}

Log* Log::setLogDesc(const QString &logDesc) {
    Log::logDesc = logDesc;
    return this;
}
