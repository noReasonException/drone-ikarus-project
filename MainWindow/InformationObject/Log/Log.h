//
// Created by noreasonexception on 4/3/18.
//

#ifndef IKARUS_PROJECT_LOG_H
#define IKARUS_PROJECT_LOG_H


#include "../InformationObject.h"

class Log : public InformationObject{
public:
    Log(QString logType,long timestamp,QString logDesc);

    const QString &getLogType() const;

    Log* setLogType(const QString &logType);

    const QString &getLogDesc() const;

    Log* setLogDesc(const QString &logDesc);

private:
    QString logType;
    QString logDesc;


};


#endif //IKARUS_PROJECT_LOG_H
