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
#ifndef IKARUS_PROJECT_SETRESOLUTIONDIALOGSTATE_H
#define IKARUS_PROJECT_SETRESOLUTIONDIALOGSTATE_H


#include "../AlanTwoButtonsDialogState.h"
#include "../../../../Dialogs/AlanTwoButtonDialog/ChildDialogs/SetResolutionDialog.h"

class SetResolutionDialogState: public AlanTwoButtonsDialogState {
public:
    SetResolutionDialogState()= default;
    QString width;
    QString height;
    virtual ~SetResolutionDialogState() = default;

    void update() override {
        AlanTwoButtonsDialogState::update();
        settings->setValue(createPath()+RESOLUTION_WIDTH_QLINEEDIT_STATE,width);
        settings->setValue(createPath()+RESOLUTION_HEIGHT_QLINEEDIT_STATE,height);
    }

    void load() override {
        AlanTwoButtonsDialogState::load();
        if(settings->contains(createPath()+RESOLUTION_WIDTH_QLINEEDIT_STATE) &&
           settings->contains(createPath()+RESOLUTION_HEIGHT_QLINEEDIT_STATE)){
            width=settings->value(createPath()+RESOLUTION_WIDTH_QLINEEDIT_STATE).toString();
            height=settings->value(createPath()+RESOLUTION_HEIGHT_QLINEEDIT_STATE).toString();
            return ;
        }
        width="0";
        height="0";
    }

    QString createPath() override {
        return AlanTwoButtonsDialogState::createPath()+SET_RESOLUTION_DIALOG_STATE_PATH;
    }
};


#endif //IKARUS_PROJECT_SETRESOLUTIONDIALOGSTATE_H
