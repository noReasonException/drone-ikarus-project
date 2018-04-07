//
// Created by noreasonexception on 4/5/18.
//

#ifndef IKARUS_PROJECT_STATE_H
#define IKARUS_PROJECT_STATE_H

////TODO : Dont forget to implement State subsystem
class State {
public:
    State()= default;
    virtual void update()=0;

};


#endif //IKARUS_PROJECT_STATE_H
