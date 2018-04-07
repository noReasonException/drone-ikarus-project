//
// Created by noreasonexception on 4/6/18.
//

#ifndef IKARUS_PROJECT_ALANSINGLEOPTIONDIALOGSTATE_H
#define IKARUS_PROJECT_ALANSINGLEOPTIONDIALOGSTATE_H

#include "../State.h"
#include <iostream>

class AlanSingleOptionDialogState: public State{
public:
    AlanSingleOptionDialogState():State(){

    }
public:
};
class AlanTwoButtonsDialogState:public AlanSingleOptionDialogState{
public:
    AlanTwoButtonsDialogState():AlanSingleOptionDialogState(){

    }

};
class AlanMultipleChoiceDialogState:public AlanTwoButtonsDialogState{
public:
    std::vector<QString>he;
    AlanMultipleChoiceDialogState():AlanTwoButtonsDialogState(){
        he.push_back("he");
        he.push_back("he");
        he.push_back("he");
    }

};
#endif //IKARUS_PROJECT_ALANSINGLEOPTIONDIALOG_H
