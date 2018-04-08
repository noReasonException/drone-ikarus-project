//
// Created by noreasonexception on 4/8/18.
//

#ifndef IKARUS_PROJECT_SETDRONEDIALOG_H
#define IKARUS_PROJECT_SETDRONEDIALOG_H


#include "../AlanMultipleChoiceDialog.h"

class SetDroneAddrDialog : public AlanMultipleChoiceDialog{
public:
    SetDroneAddrDialog(AlanMultipleChoiceDialogState *state) : AlanMultipleChoiceDialog(state, "Set Drones Address", DRONE_ADDR_ICON, "+") {}

protected:
    void onAdditionalButtonSlot() override {
        QMessageBox::warning(nullptr,"aaa","aaaaa");
    }

    void onClickedChoiceSlot(QListWidgetItem *item) override {
        QMessageBox::warning(nullptr,"bbb","bbbbbbb");

    }

    void onOkButtonSlot() override {
        QMessageBox::warning(nullptr,"ccc","ccccc");


    }
};


#endif //IKARUS_PROJECT_SETDRONEDIALOG_H
