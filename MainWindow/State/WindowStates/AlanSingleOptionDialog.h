//
// Created by noreasonexception on 4/6/18.
//

#ifndef IKARUS_PROJECT_ALANSINGLEOPTIONDIALOGSTATE_H
#define IKARUS_PROJECT_ALANSINGLEOPTIONDIALOGSTATE_H

#include "../State.h"
#include "../../Supplier/LogSupplier/LogSupplier.h"
#include "../../Panels/StreamPanel/LogPanel/LogPanel.h"
#include <iostream>

class AlanSingleOptionDialogState: public State{
public:
    AlanSingleOptionDialogState()= default;
    virtual ~AlanSingleOptionDialogState()= default;
    virtual void update() override {}

public:
};
class AlanTwoButtonsDialogState:public AlanSingleOptionDialogState{
public:
    AlanTwoButtonsDialogState()= default;
    virtual ~AlanTwoButtonsDialogState()= default;
    virtual void update() override {}

};
class AlanMultipleChoiceDialogState:public AlanTwoButtonsDialogState{
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
#endif //IKARUS_PROJECT_ALANSINGLEOPTIONDIALOG_H
