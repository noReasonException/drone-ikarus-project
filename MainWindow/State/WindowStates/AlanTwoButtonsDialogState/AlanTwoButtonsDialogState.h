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
#ifndef IKARUS_PROJECT_ALANTWOBUTTONSDIALOGSTATE_H
#define IKARUS_PROJECT_ALANTWOBUTTONSDIALOGSTATE_H


#include "../../../../InformationObject/Log/Log.h"
#include "../AlanSingleOptionDialogState.h"
#include "../../../../Supplier/LogSupplier/LogSupplier.h"

class AlanTwoButtonsDialogState: public AlanSingleOptionDialogState{
public:
    AlanTwoButtonsDialogState()= default;
    virtual ~AlanTwoButtonsDialogState()= default;


    QString createPath() override {
        return AlanSingleOptionDialogState::createPath()+TWO_BUTTONS_DIALOG_STATE_PATH;
    }
};
#endif //IKARUS_PROJECT_ALANTWOBUTTONSDIALOGSTATE_H
