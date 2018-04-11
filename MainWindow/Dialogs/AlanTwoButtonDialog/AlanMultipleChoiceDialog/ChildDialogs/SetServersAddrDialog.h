//
// Created by noreasonexception on 4/8/18.
//

#ifndef IKARUS_PROJECT_SETSERVERSADDRDIALOG_H
#define IKARUS_PROJECT_SETSERVERSADDRDIALOG_H


#include "../../../../State/WindowStates/AlanSingleOptionDialogState.h"
#include "../AlanMultipleChoiceDialog.h"

class SetServersAddrDialog : public AlanMultipleChoiceDialog{
public:
    SetServersAddrDialog(AlanMultipleChoiceDialogState *state) : AlanMultipleChoiceDialog(state, SERVER_ADDR_DIALOG_TITLE, SERVER_ADDR_ICON, "+") {

    }


protected:
    void onAdditionalButtonSlot() override {
        listWidget->addItem(lineEdit->text());
        onSaveState();
    }

    void onClickedChoiceSlot(QListWidgetItem *item) override {
        QMessageBox::warning(nullptr,"bbb2","bbbbbbb2");

    }

    bool generic_initializer() override {
        return AlanMultipleChoiceDialog::generic_initializer()&&onRestoreState();
    }

};


#endif //IKARUS_PROJECT_SETSERVERSADDRDIALOG_H
