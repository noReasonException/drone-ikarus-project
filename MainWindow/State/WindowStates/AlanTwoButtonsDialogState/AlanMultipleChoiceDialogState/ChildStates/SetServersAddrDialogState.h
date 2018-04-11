//
// Created by noreasonexception on 4/10/18.
//

#ifndef IKARUS_PROJECT_SETSERVERSADDRDIALOGSTATE_H
#define IKARUS_PROJECT_SETSERVERSADDRDIALOGSTATE_H


#include "../AlanMultipleChoiceDialogState.h"
#include "../../../../../Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/ChildDialogs/SetServersAddrDialog.h"

class SetServersAddrDialogState : public AlanMultipleChoiceDialogState{
public:
    SetServersAddrDialogState() = default;

    virtual ~SetServersAddrDialogState() = default;

    void update() override {

    }
    QString createPath() override {
        return AlanMultipleChoiceDialogState::createPath()+SET_SERVERS_ADDR_DIALOG_STATE_PATH;
    }
};

#endif //IKARUS_PROJECT_SETSERVERSADDRDIALOGSTATE_H
