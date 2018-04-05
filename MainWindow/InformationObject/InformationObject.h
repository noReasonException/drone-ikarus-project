//
// Created by noreasonexception on 4/3/18.
//

#ifndef IKARUS_PROJECT_INFORMATIONOBJECT_H
#define IKARUS_PROJECT_INFORMATIONOBJECT_H


#include "../Consumer/InformationObjectConsumer.h"
class InformationObjectSupplier;

class InformationObject {
public:
    explicit InformationObject(long timestamp,InformationObjectSupplier*source);
    virtual ~InformationObject()= default;//TODO memory leak fix

private:
    long timestamp;
    InformationObjectSupplier * source;
public:
    long getTimestamp() const;

    InformationObject* setTimestamp(long timestamp);

    InformationObjectSupplier *getSource() const;

    InformationObject* setSource(InformationObjectSupplier *source);

};


#endif //IKARUS_PROJECT_INFORMATIONOBJECT_H
