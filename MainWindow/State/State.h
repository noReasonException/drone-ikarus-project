//
// Created by noreasonexception on 4/5/18.
//

#ifndef IKARUS_PROJECT_STATE_H
#define IKARUS_PROJECT_STATE_H

#include <QSettings>
#include <QString>

////TODO : Dont forget to implement State subsystem
class State {
public:
    State()= default;
    virtual void update()=0;
    virtual QString createPath()=0;
protected:
    static QSettings settings;


};


#endif //IKARUS_PROJECT_STATE_H
