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
#include "../../../../Supplier/OptionSupplier/OptionSupplier.h"

class SetLatencyDialog : public AlanTwoButtonDialog{
public:
    SetLatencyDialog(AlanTwoButtonsDialogState *state,OptionSupplier *supplier):
            AlanTwoButtonDialog(state,LATENCY_DIALOG_TITLE,LATENCY_ICON),
            rtspClientOptionSupplier(supplier){
        std::cout<<supplier<<"COME AS SUPPLER (LANCY)"<<std::endl;
    }

private:
    QLineEdit *input;
    OptionSupplier*rtspClientOptionSupplier;
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
        thisState->load();
        input->setText(thisState->latencyInput);

        return thisState;
    }
    SetLatencyDialogState *onSaveState() throw(std::exception)override {
        SetLatencyDialogState*thisState= dynamic_cast<SetLatencyDialogState*>(AlanTwoButtonDialog::onSaveState());
        thisState->latencyInput=input->text();
        thisState->update();
        getRtspClientOptionSupplier()->send(new class LatencyOption(
                12,
                time(NULL),
                getRtspClientOptionSupplier()));
        std::cout<<"onSaveState"<<std::endl;
        return thisState;
    }

    bool generic_initializer() override {
        return AlanTwoButtonDialog::generic_initializer()&&
                onRestoreState();
    }

    OptionSupplier *getRtspClientOptionSupplier() const {
        return rtspClientOptionSupplier;
    }
};


#endif //IKARUS_PROJECT_SETLATENCYDIALOG_H
