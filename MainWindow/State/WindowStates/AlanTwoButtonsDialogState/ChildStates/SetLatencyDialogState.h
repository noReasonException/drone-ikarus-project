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
#ifndef IKARUS_PROJECT_SETLATENCYDIALOGSTATE_H
#define IKARUS_PROJECT_SETLATENCYDIALOGSTATE_H


#include "../AlanTwoButtonsDialogState.h"
#include "../../../../Dialogs/AlanTwoButtonDialog/ChildDialogs/SetLatencyDialog.h"

class SetLatencyDialogState: public AlanTwoButtonsDialogState{
public:

    SetLatencyDialogState() = default;

    QString latencyInput;
    virtual ~SetLatencyDialogState() = default;

    void update() override {
        AlanTwoButtonsDialogState::update();
        settings->setValue(createPath()+LATENCY_INPUT_QLINEEDIT_STATE,latencyInput);
    }

    void load() override {
        AlanTwoButtonsDialogState::load();
        if(settings->contains(createPath()+LATENCY_INPUT_QLINEEDIT_STATE)){
            latencyInput=settings->value(createPath()+LATENCY_INPUT_QLINEEDIT_STATE).toString();
            return ;
        }
        latencyInput="0";
    }

private:

    QString createPath() override {
        return AlanTwoButtonsDialogState::createPath()+SET_LATENCY_DIALOG_STATE_PATH;
    }
};


#endif //IKARUS_PROJECT_SETLATENCYDIALOGSTATE_H
