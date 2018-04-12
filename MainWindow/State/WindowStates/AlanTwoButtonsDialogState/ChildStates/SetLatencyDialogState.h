//
// Created by noreasonexception on 4/10/18.
//

#ifndef IKARUS_PROJECT_SETLATENCYDIALOGSTATE_H
#define IKARUS_PROJECT_SETLATENCYDIALOGSTATE_H


#include "../AlanTwoButtonsDialogState.h"
#include "../../../../Dialogs/AlanTwoButtonDialog/ChildDialogs/SetLatencyDialog.h"

class SetLatencyDialogState: public AlanTwoButtonsDialogState{
public:

    SetLatencyDialogState() = default;

    QString latencyInput;
    virtual ~SetLatencyDialogState() = default;

    void update() override {
        AlanTwoButtonsDialogState::update();
        settings->setValue(createPath()+LATENCY_INPUT_QLINEEDIT_STATE,latencyInput);
    }

    void load() override {
        AlanTwoButtonsDialogState::load();
        if(settings->contains(createPath()+LATENCY_INPUT_QLINEEDIT_STATE)){
            latencyInput=settings->value(createPath()+LATENCY_INPUT_QLINEEDIT_STATE).toString();
            return ;
        }
        latencyInput="0";
    }

private:

    QString createPath() override {
        return AlanTwoButtonsDialogState::createPath()+SET_LATENCY_DIALOG_STATE_PATH;
    }
};


#endif //IKARUS_PROJECT_SETLATENCYDIALOGSTATE_H
