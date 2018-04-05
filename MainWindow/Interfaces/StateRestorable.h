//
// Created by noreasonexception on 4/5/18.
//

#ifndef IKARUS_PROJECT_STATERESTORABLE_H
#define IKARUS_PROJECT_STATERESTORABLE_H

#include "../State/State.h"

class StateRestorable{
public:
    StateRestorable()= delete;

    virtual void restoreTo(State*)=0;
};
#endif //IKARUS_PROJECT_STATERESTORABLE_H
