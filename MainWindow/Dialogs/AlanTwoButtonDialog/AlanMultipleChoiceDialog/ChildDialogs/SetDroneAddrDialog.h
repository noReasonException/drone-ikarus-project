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
#ifndef IKARUS_PROJECT_SETDRONEDIALOG_H
#define IKARUS_PROJECT_SETDRONEDIALOG_H


#include "../AlanMultipleChoiceDialog.h"
#include "../../../../../res/generic_text/AlanMainWindowText.h"
#include "../../../../../Supplier/OptionSupplier/OptionSupplier.h"
#include "../../../../../InformationObject/Option/ChildOptions/LocationOption.h"
#include "../../../../../res/generic_text/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/ChildDialogs/SetDroneAddrDialogText.h"

class SetDroneAddrDialog : public AlanMultipleChoiceDialog{
public:
    SetDroneAddrDialog(AlanMultipleChoiceDialogState *state,OptionSupplier*supplier) :
            AlanMultipleChoiceDialog(state, DRONE_ADDR_DIALOG_TITLE, DRONE_ADDR_ICON, SET_DRONE_ADDR_DIALOG_ADD_BTN),
    rtspClientOptionSupplier(supplier){}

protected:
    void onAdditionalButtonSlot() override {
        listWidget->addItem(lineEdit->text());
        onSaveState();
    }

    void onClickedChoiceSlot(QListWidgetItem *item) override {
        getRtspClientOptionSupplier()->send(new class LocationOption(
                listWidget->item(listWidget->currentRow())->text(),
                time(NULL),
                getRtspClientOptionSupplier()));

    }

    bool generic_initializer() override {
        return AlanMultipleChoiceDialog::generic_initializer()&&onRestoreState();
    }

    OptionSupplier *getRtspClientOptionSupplier() const {
        return rtspClientOptionSupplier;
    }

private:
    OptionSupplier*rtspClientOptionSupplier;

};


#endif //IKARUS_PROJECT_SETDRONEDIALOG_H
