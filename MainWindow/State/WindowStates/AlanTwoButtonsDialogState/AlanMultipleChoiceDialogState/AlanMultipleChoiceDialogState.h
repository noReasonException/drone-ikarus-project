//
// Created by noreasonexception on 4/10/18.
//

#ifndef IKARUS_PROJECT_ALANMULTIPLECHOICEDIALOGSTATE_H
#define IKARUS_PROJECT_ALANMULTIPLECHOICEDIALOGSTATE_H


#include "../../../../InformationObject/Log/Log.h"
#include "../AlanTwoButtonsDialogState.h"
#include <iostream>


class AlanMultipleChoiceDialogState: public AlanTwoButtonsDialogState{
public:
    AlanMultipleChoiceDialogState(){
        if(State::settings.contains(createPath()+MULTIPLE_CHOICES_STATE)){

            for (int i = 0; i < State::settings.beginReadArray(createPath()+MULTIPLE_CHOICES_STATE); ++i) {
                multipleChoices.push_back(State::settings.value(MULTIPLE_STATE_AT_INDEX+QString(i)).toString());
                std::cout<<i;
            }
            State::settings.endArray();
        }
    }

    std::vector<QString> multipleChoices;

    virtual ~AlanMultipleChoiceDialogState() = default;

    void update() override {
        State::settings.beginWriteArray(createPath()+MULTIPLE_CHOICES_STATE);
        for (int i = 0; i < multipleChoices.size(); ++i) {
            State::settings.setArrayIndex(i);
            State::settings.setValue(MULTIPLE_STATE_AT_INDEX+QString(i),multipleChoices[i]);
        }
        State::settings.endArray();

    }

    QString createPath() override {
        return AlanTwoButtonsDialogState::createPath()+MULTIPLE_CHOICE_DIALOG_STATE_PATH;
    }
};

#endif //IKARUS_PROJECT_ALANMULTIPLECHOICEDIALOGSTATE_H
