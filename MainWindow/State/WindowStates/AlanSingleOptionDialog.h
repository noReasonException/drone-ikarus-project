//
// Created by noreasonexception on 4/6/18.
//

#ifndef IKARUS_PROJECT_ALANSINGLEOPTIONDIALOGSTATE_H
#define IKARUS_PROJECT_ALANSINGLEOPTIONDIALOGSTATE_H

#include "../State.h"

class AlanSingleOptionDialogState: public State{
public:
    std::string o="3";
};
class AlanTwoButtonsDialogState:public AlanSingleOptionDialogState{
    std::string t="2";

};
class AlanMultipleChoiceDialogState:public AlanTwoButtonsDialogState{
    std::string tr="1";

public:
    std::vector<QString> MultipleChoices;
    AlanMultipleChoiceDialogState(){
        MultipleChoices.push_back("he");
    }

};
#endif //IKARUS_PROJECT_ALANSINGLEOPTIONDIALOG_H
