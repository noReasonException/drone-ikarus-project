//
// Created by noreasonexception on 4/10/18.
//

#ifndef IKARUS_PROJECT_ALANTWOBUTTONSDIALOGSTATE_H
#define IKARUS_PROJECT_ALANTWOBUTTONSDIALOGSTATE_H


#include "../../../InformationObject/Log/Log.h"
#include "../AlanSingleOptionDialogState.h"
#include "../../../Supplier/LogSupplier/LogSupplier.h"

class AlanTwoButtonsDialogState: public AlanSingleOptionDialogState{
public:
    AlanTwoButtonsDialogState()= default;
    virtual ~AlanTwoButtonsDialogState()= default;
    virtual void update() override {}

};
#endif //IKARUS_PROJECT_ALANTWOBUTTONSDIALOGSTATE_H
