//
// Created by noreasonexception on 4/8/18.
//

#ifndef IKARUS_PROJECT_SETSERVERSADDRDIALOG_H
#define IKARUS_PROJECT_SETSERVERSADDRDIALOG_H


#include "../../../../State/WindowStates/AlanSingleOptionDialog.h"
#include "../AlanMultipleChoiceDialog.h"

class setServersAddrDialog : public AlanMultipleChoiceDialog{
public:
    setServersAddrDialog(AlanMultipleChoiceDialogState *state, const QString &title, const QString &icon,
                         const QString &buttonText) : AlanMultipleChoiceDialog(state, title, icon, buttonText) {}

protected:
    void onAdditionalButtonSlot() override {
        QMessageBox::warning(nullptr,"aaa2","aaaaa2");
    }

    void onClickedChoiceSlot(QListWidgetItem *item) override {
        QMessageBox::warning(nullptr,"bbb2","bbbbbbb2");

    }

    void onOkButtonSlot() override {
        QMessageBox::warning(nullptr,"ccc2","ccccc2");


    }

};


#endif //IKARUS_PROJECT_SETSERVERSADDRDIALOG_H
