//
// Created by noreasonexception on 4/10/18.
//

#ifndef IKARUS_PROJECT_SETRESOLUTIONDIALOGSTATE_H
#define IKARUS_PROJECT_SETRESOLUTIONDIALOGSTATE_H


#include "../AlanTwoButtonsDialogState.h"
#include "../../../../Dialogs/AlanTwoButtonDialog/ChildDialogs/SetResolutionDialog.h"

class SetResolutionDialogState: AlanTwoButtonsDialogState {
public:
    SetResolutionDialogState() = default;

    virtual ~SetResolutionDialogState() = default;

private:
    void update() override {
        AlanTwoButtonsDialogState::update();
    }

    QString createPath() override {
        return AlanTwoButtonsDialogState::createPath()+SET_RESOLUTION_DIALOG_STATE_PATH;
    }
};


#endif //IKARUS_PROJECT_SETRESOLUTIONDIALOGSTATE_H
