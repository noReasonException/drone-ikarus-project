//
// Created by noreasonexception on 4/10/18.
//

#ifndef IKARUS_PROJECT_SETLATENCYDIALOGSTATE_H
#define IKARUS_PROJECT_SETLATENCYDIALOGSTATE_H


#include "../AlanTwoButtonsDialogState.h"

class SetLatencyDialogState: AlanTwoButtonsDialogState{
public:
    SetLatencyDialogState() = default;

    virtual ~SetLatencyDialogState() = default;

private:
    void update() override {
        AlanTwoButtonsDialogState::update();
    }

    QString createPath() override {
        return AlanTwoButtonsDialogState::createPath()+SET_LATENCY_DIALOG_STATE_PATH;
    }
};


#endif //IKARUS_PROJECT_SETLATENCYDIALOGSTATE_H
