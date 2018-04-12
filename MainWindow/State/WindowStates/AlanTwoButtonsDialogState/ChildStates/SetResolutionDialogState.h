//
// Created by noreasonexception on 4/10/18.
//

#ifndef IKARUS_PROJECT_SETRESOLUTIONDIALOGSTATE_H
#define IKARUS_PROJECT_SETRESOLUTIONDIALOGSTATE_H


#include "../AlanTwoButtonsDialogState.h"
#include "../../../../Dialogs/AlanTwoButtonDialog/ChildDialogs/SetResolutionDialog.h"

class SetResolutionDialogState: public AlanTwoButtonsDialogState {
public:
    SetResolutionDialogState()= default;
    QString width;
    QString height;
    virtual ~SetResolutionDialogState() = default;

    void update() override {
        AlanTwoButtonsDialogState::update();
        settings->setValue(createPath()+RESOLUTION_WIDTH_QLINEEDIT_STATE,width);
        settings->setValue(createPath()+RESOLUTION_HEIGHT_QLINEEDIT_STATE,height);
    }

    void load() override {
        AlanTwoButtonsDialogState::load();
        if(settings->contains(createPath()+RESOLUTION_WIDTH_QLINEEDIT_STATE) &&
           settings->contains(createPath()+RESOLUTION_HEIGHT_QLINEEDIT_STATE)){
            width=settings->value(createPath()+RESOLUTION_WIDTH_QLINEEDIT_STATE).toString();
            height=settings->value(createPath()+RESOLUTION_HEIGHT_QLINEEDIT_STATE).toString();
            return ;
        }
        width="0";
        height="0";
    }

    QString createPath() override {
        return AlanTwoButtonsDialogState::createPath()+SET_RESOLUTION_DIALOG_STATE_PATH;
    }
};


#endif //IKARUS_PROJECT_SETRESOLUTIONDIALOGSTATE_H
