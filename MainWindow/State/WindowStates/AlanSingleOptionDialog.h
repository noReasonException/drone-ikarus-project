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
#endif //IKARUS_PROJECT_ALANSINGLEOPTIONDIALOG_H
