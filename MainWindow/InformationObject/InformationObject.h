//
// Created by noreasonexception on 4/3/18.
//

#ifndef IKARUS_PROJECT_INFORMATIONOBJECT_H
#define IKARUS_PROJECT_INFORMATIONOBJECT_H


class InformationObject {
public:
    explicit InformationObject(long timestamp);

private:
    long timestamp;
public:
    long getTimestamp() const;
    InformationObject* setTimestamp(long timestamp);

};


#endif //IKARUS_PROJECT_INFORMATIONOBJECT_H
