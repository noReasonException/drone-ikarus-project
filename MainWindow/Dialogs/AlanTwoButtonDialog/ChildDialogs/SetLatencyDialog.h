//
// Created by noreasonexception on 4/8/18.
//

#ifndef IKARUS_PROJECT_SETLATENCYDIALOG_H
#define IKARUS_PROJECT_SETLATENCYDIALOG_H


#include <QMessageBox>
#include <QLineEdit>
#include <QGridLayout>
#include "../AlanTwoButtonDialog.h"
#include "../../../../misc/img/generic_paths.h"
#include "../../../State/WindowStates/AlanTwoButtonsDialogState/AlanTwoButtonsDialogState.h"
#include "../../../State/WindowStates/AlanTwoButtonsDialogState/ChildStates/SetResolutionDialogState.h"
#include "../../../State/WindowStates/AlanTwoButtonsDialogState/ChildStates/SetLatencyDialogState.h"

class SetLatencyDialog : public AlanTwoButtonDialog{
public:
    SetLatencyDialog(AlanTwoButtonsDialogState *state):AlanTwoButtonDialog(state,LATENCY_DIALOG_TITLE,LATENCY_ICON){}

private:
    QLineEdit *input;
    QWidget *onGenerateConfigArea() throw (std::exception)override {
        QWidget*widget=new QWidget;
        QHBoxLayout*lay;
        widget->setLayout(lay=new QHBoxLayout);
        lay->addWidget(input=new QLineEdit);
        lay->addWidget(new QLabel("ms"));
        return widget;

    }

protected:
    SetLatencyDialogState *onRestoreState() throw(std::exception)override {
        SetLatencyDialogState*thisState= dynamic_cast<SetLatencyDialogState*>(AlanTwoButtonDialog::onRestoreState());
        input->setText(thisState->latencyInput);
        return thisState;
    }
    SetLatencyDialogState *onSaveState() throw(std::exception)override {
        SetLatencyDialogState*thisState= dynamic_cast<SetLatencyDialogState*>(AlanTwoButtonDialog::onRestoreState());
        thisState->latencyInput=input->text();
        return thisState;
    }

    bool generic_initializer() override {
        return AlanTwoButtonDialog::generic_initializer()&&
                onRestoreState();
    }

};


#endif //IKARUS_PROJECT_SETLATENCYDIALOG_H
