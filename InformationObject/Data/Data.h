//
// Created by noreasonexception on 4/3/18.
//

#ifndef IKARUS_PROJECT_DATA_H
#define IKARUS_PROJECT_DATA_H


#include "../InformationObject.h"

class Data : public InformationObject{

private:
    int ID;
public:
    int getID() const;

    void setID(int ID);
    Data(int ID,long timestamp, InformationObjectSupplier *source);




};


#endif //IKARUS_PROJECT_DATA_H
