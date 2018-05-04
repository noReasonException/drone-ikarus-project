//
// Created by noreasonexception on 4/8/18.
//

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
