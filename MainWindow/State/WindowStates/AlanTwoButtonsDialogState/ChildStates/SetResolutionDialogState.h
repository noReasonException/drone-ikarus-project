//
// Created by noreasonexception on 4/10/18.
//

#ifndef IKARUS_PROJECT_SETRESOLUTIONDIALOGSTATE_H
#define IKARUS_PROJECT_SETRESOLUTIONDIALOGSTATE_H


#include "../AlanTwoButtonsDialogState.h"
#include "../../../../Dialogs/AlanTwoButtonDialog/ChildDialogs/SetResolutionDialog.h"

class SetResolutionDialogState: public AlanTwoButtonsDialogState {
public:
    SetResolutionDialogState(){
        if(State::settings.contains(createPath()+RESOLUTION_WIDTH_QLINEEDIT_STATE) &&
                State::settings.contains(createPath()+RESOLUTION_HEIGHT_QLINEEDIT_STATE)){
            width=State::settings.value(createPath()+RESOLUTION_WIDTH_QLINEEDIT_STATE).toString();
            height=State::settings.value(createPath()+RESOLUTION_HEIGHT_QLINEEDIT_STATE).toString();
            return ;
        }
        width="0";
        height="0";
    };
    QString width;
    QString height;
    virtual ~SetResolutionDialogState() = default;

    void update() override {
        settings.setValue(createPath()+RESOLUTION_WIDTH_QLINEEDIT_STATE,width);
        settings.setValue(createPath()+RESOLUTION_HEIGHT_QLINEEDIT_STATE,height);
    }

    QString createPath() override {
        return AlanTwoButtonsDialogState::createPath()+SET_RESOLUTION_DIALOG_STATE_PATH;
    }
};


#endif //IKARUS_PROJECT_SETRESOLUTIONDIALOGSTATE_H
