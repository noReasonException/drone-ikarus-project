//
// Created by noreasonexception on 4/8/18.
//

#ifndef IKARUS_PROJECT_SETDRONEDIALOG_H
#define IKARUS_PROJECT_SETDRONEDIALOG_H


#include "../AlanMultipleChoiceDialog.h"

class setDroneDialog : public AlanMultipleChoiceDialog{
public:
    setDroneDialog(AlanMultipleChoiceDialogState *state, const QString &title, const QString &icon,
                   const QString &buttonText) : AlanMultipleChoiceDialog(state, title, icon, buttonText) {}

protected:
    void onAdditionalButtonSlot() override {

    }

    void onClickedChoiceSlot(QListWidgetItem *item) override {

    }

    void onOkButtonSlot() override {

    }
};


#endif //IKARUS_PROJECT_SETDRONEDIALOG_H
