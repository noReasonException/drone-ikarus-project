//
// Created by noreasonexception on 4/10/18.
//

#ifndef IKARUS_PROJECT_SETDRONEADDRDIALOGSTATE_H
#define IKARUS_PROJECT_SETDRONEADDRDIALOGSTATE_H


#include "../AlanMultipleChoiceDialogState.h"

class SetDroneAddrDialogState : public AlanMultipleChoiceDialogState{
public:
    SetDroneAddrDialogState() = default;

    virtual ~SetDroneAddrDialogState() = default;

    void update() override {
        AlanMultipleChoiceDialogState::update();
    }

    QString createPath() override {
        return AlanMultipleChoiceDialogState::createPath()+SET_DRONE_ADDR_DIALOG_STATE_PATH;
    }
};


#endif //IKARUS_PROJECT_SETDRONEADDRDIALOGSTATE_H
