/*
 * Copyright (C) 2018 Stefanos Stefanou
 * This file is part of AlanStreamer.

    AlanStreamer is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    AlanStreamer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.


    You should have received a copy of the GNU General Public License
    along with AlanStreamer.  If not, see <http://www.gnu.org/licenses/>.

 */
#ifndef IKARUS_PROJECT_ALANSINGLEOPTIONDIALOGSTATE_H
#define IKARUS_PROJECT_ALANSINGLEOPTIONDIALOGSTATE_H

#include "../State.h"
#include "../../../Supplier/LogSupplier/LogSupplier.h"
#include "../../Panels/StreamPanel/LogPanel/LogPanel.h"
#include "../../../res/states.h"
#include <iostream>

class AlanSingleOptionDialogState: public State{
public:
    AlanSingleOptionDialogState()= default;
    virtual ~AlanSingleOptionDialogState()= default;


    void update() override { return;}

    void load() override { return; }

    QString createPath() override{
        return SINGLE_OPTION_DIALOG_STATE_PATH;
    }

public:
};
#endif //IKARUS_PROJECT_ALANSINGLEOPTIONDIALOG_H
