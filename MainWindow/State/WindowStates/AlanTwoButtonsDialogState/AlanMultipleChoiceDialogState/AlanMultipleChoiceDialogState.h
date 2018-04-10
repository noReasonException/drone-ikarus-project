//
// Created by noreasonexception on 4/10/18.
//

#ifndef IKARUS_PROJECT_ALANMULTIPLECHOICEDIALOGSTATE_H
#define IKARUS_PROJECT_ALANMULTIPLECHOICEDIALOGSTATE_H


#include "../../../../InformationObject/Log/Log.h"
#include "../AlanTwoButtonsDialogState.h"

class AlanMultipleChoiceDialogState: public AlanTwoButtonsDialogState{
public:
    const std::vector<QString> &getListViewData() const{ return listViewData;}

    void update() override {
        supl->send(new Log("Update-Inner-State",time(NULL),"-",supl));
    }

    AlanMultipleChoiceDialogState* setListViewData(const std::vector<QString> &listViewData){this->listViewData=listViewData;return this;}

    AlanMultipleChoiceDialogState(){
        supl=LogPanel::getInstance("")->createSupplier("AlanMultipleChoiceDialogState");
    }
    virtual ~AlanMultipleChoiceDialogState()= default;

protected:
    std::vector<QString>listViewData;
    LogSupplier*supl;



};

#endif //IKARUS_PROJECT_ALANMULTIPLECHOICEDIALOGSTATE_H
