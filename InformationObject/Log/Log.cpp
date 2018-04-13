//
// Created by noreasonexception on 4/3/18.
//

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
