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
#ifndef IKARUS_PROJECT_SETSERVERSADDRDIALOG_H
#define IKARUS_PROJECT_SETSERVERSADDRDIALOG_H


#include "../../../../State/WindowStates/AlanSingleOptionDialogState.h"
#include "../AlanMultipleChoiceDialog.h"
#include "../../../../../res/generic_text/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/ChildDialogs/SetServersAddrDialogText.h"

class OptionSupplier;
class SetServersAddrDialog : public AlanMultipleChoiceDialog{
private:
    OptionSupplier*rtspClientOptionSupplier;

public:
    SetServersAddrDialog(AlanMultipleChoiceDialogState *state,OptionSupplier*supplier) :
            AlanMultipleChoiceDialog(state, SERVER_ADDR_DIALOG_TITLE, SERVER_ADDR_ICON, SET_SERVER_ADDR_DIALOG_ADD_BTN),
            rtspClientOptionSupplier(supplier){

    }


protected:
    OptionSupplier *getRtspClientOptionSupplier() const {
        return rtspClientOptionSupplier;
    }

    void onAdditionalButtonSlot() override {
        listWidget->addItem(lineEdit->text());
        onSaveState();
    }

    void onClickedChoiceSlot(QListWidgetItem *item) override {


    }

    bool generic_initializer() override {
        return AlanMultipleChoiceDialog::generic_initializer()&&onRestoreState();
    }

};


#endif //IKARUS_PROJECT_SETSERVERSADDRDIALOG_H
