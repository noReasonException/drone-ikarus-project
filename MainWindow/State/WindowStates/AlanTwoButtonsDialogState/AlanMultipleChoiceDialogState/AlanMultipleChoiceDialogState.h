//
// Created by noreasonexception on 4/10/18.
//

#ifndef IKARUS_PROJECT_ALANMULTIPLECHOICEDIALOGSTATE_H
#define IKARUS_PROJECT_ALANMULTIPLECHOICEDIALOGSTATE_H


#include "../../../../InformationObject/Log/Log.h"
#include "../AlanTwoButtonsDialogState.h"

class AlanMultipleChoiceDialogState: public AlanTwoButtonsDialogState{
public:
    AlanMultipleChoiceDialogState() = default;

    virtual ~AlanMultipleChoiceDialogState() = default;

    void update() override {
        AlanTwoButtonsDialogState::update();
    }

    QString createPath() override {
        return AlanTwoButtonsDialogState::createPath()+MULTIPLE_CHOICE_DIALOG_STATE_PATH;
    }
};

#endif //IKARUS_PROJECT_ALANMULTIPLECHOICEDIALOGSTATE_H
