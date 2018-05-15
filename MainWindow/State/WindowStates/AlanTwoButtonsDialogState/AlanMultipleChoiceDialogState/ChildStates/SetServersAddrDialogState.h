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
#ifndef IKARUS_PROJECT_SETSERVERSADDRDIALOGSTATE_H
#define IKARUS_PROJECT_SETSERVERSADDRDIALOGSTATE_H


#include "../AlanMultipleChoiceDialogState.h"
#include "../../../../../Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/ChildDialogs/SetServersAddrDialog.h"

class SetServersAddrDialogState : public AlanMultipleChoiceDialogState{
public:
    SetServersAddrDialogState() :AlanMultipleChoiceDialogState(){}

    virtual ~SetServersAddrDialogState() = default;


    QString createPath() override {
        return AlanMultipleChoiceDialogState::createPath()+SET_SERVERS_ADDR_DIALOG_STATE_PATH;
    }
};

#endif //IKARUS_PROJECT_SETSERVERSADDRDIALOGSTATE_H
