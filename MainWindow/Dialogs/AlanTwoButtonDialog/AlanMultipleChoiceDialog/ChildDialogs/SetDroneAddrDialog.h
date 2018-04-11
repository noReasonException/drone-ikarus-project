//
// Created by noreasonexception on 4/8/18.
//

#ifndef IKARUS_PROJECT_SETDRONEDIALOG_H
#define IKARUS_PROJECT_SETDRONEDIALOG_H


#include "../AlanMultipleChoiceDialog.h"
#include "../../../../../misc/generic_text/AlanMainWindowDialogs.h"

class SetDroneAddrDialog : public AlanMultipleChoiceDialog{
public:
    SetDroneAddrDialog(AlanMultipleChoiceDialogState *state) :
            AlanMultipleChoiceDialog(state, DRONE_ADDR_DIALOG_TITLE, DRONE_ADDR_ICON, "+") {}

protected:
    void onAdditionalButtonSlot() override {
        listWidget->addItem(lineEdit->text());
        onSaveState();
    }

    void onClickedChoiceSlot(QListWidgetItem *item) override {
        QMessageBox::warning(nullptr,"bbb","bbbbbbb");

    }
};


#endif //IKARUS_PROJECT_SETDRONEDIALOG_H
