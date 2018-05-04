//
// Created by noreasonexception on 4/8/18.
//

#ifndef IKARUS_PROJECT_SETDRONEDIALOG_H
#define IKARUS_PROJECT_SETDRONEDIALOG_H


#include "../AlanMultipleChoiceDialog.h"
#include "../../../../../misc/generic_text/AlanMainWindowDialogs.h"
#include "../../../../../Supplier/OptionSupplier/OptionSupplier.h"
#include "../../../../../InformationObject/Option/ChildOptions/LocationOption.h"
#include "../../../../../misc/generic_text/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/ChildDialogs/SetDroneAddrDialogText.h"

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
