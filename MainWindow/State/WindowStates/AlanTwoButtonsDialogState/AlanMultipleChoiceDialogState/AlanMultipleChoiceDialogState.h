//
// Created by noreasonexception on 4/10/18.
//

#ifndef IKARUS_PROJECT_ALANMULTIPLECHOICEDIALOGSTATE_H
#define IKARUS_PROJECT_ALANMULTIPLECHOICEDIALOGSTATE_H


#include "../../../../InformationObject/Log/Log.h"
#include "../AlanTwoButtonsDialogState.h"

class AlanMultipleChoiceDialogState: public AlanTwoButtonsDialogState{
public:
    static std::vector<QString> testsrc;
    std::vector<QString> multipleChoices;
    AlanMultipleChoiceDialogState() {
        for (int i = 0; i < State::settings.beginReadArray(createPath() + MULTIPLE_CHOICES_STATE); ++i) {
            State::settings.setArrayIndex(i);
            multipleChoices.push_back(State::settings.value(MULTIPLE_STATE_AT_INDEX).toString());
            std::cout << i;
        }
        State::settings.endArray();
        /*for (QString &temp:testsrc){
            multipleChoices.push_back(temp);
        }*/
    }

    virtual ~AlanMultipleChoiceDialogState() = default;




    void update() override {

        State::settings.remove(createPath()+MULTIPLE_CHOICES_STATE);
        State::settings.beginWriteArray(createPath()+MULTIPLE_CHOICES_STATE);
        for (int i = 0; i < multipleChoices.size(); ++i) {
            State::settings.setArrayIndex(i);
            State::settings.setValue(MULTIPLE_STATE_AT_INDEX,multipleChoices[i]);
        }
        State::settings.endArray();
        /*AlanMultipleChoiceDialogState::testsrc.clear();
        for(QString&tmp:multipleChoices){
            AlanMultipleChoiceDialogState::testsrc.push_back(tmp);
        }*/

    }

    QString createPath() override {
        return AlanTwoButtonsDialogState::createPath()+MULTIPLE_CHOICE_DIALOG_STATE_PATH;
    }
};

#endif //IKARUS_PROJECT_ALANMULTIPLECHOICEDIALOGSTATE_H
