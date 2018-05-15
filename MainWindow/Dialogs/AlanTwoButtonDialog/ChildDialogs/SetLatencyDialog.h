/*
 * Copyright (C) 2018 Stefanos Stefanou
 * This file is part of AlanStreamer.

    AlanStreamer is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    AlanStreamer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.


    You should have received a copy of the GNU General Public License
    along with AlanStreamer.  If not, see <http://www.gnu.org/licenses/>.

 */
#ifndef IKARUS_PROJECT_SETLATENCYDIALOG_H
#define IKARUS_PROJECT_SETLATENCYDIALOG_H


#include <QMessageBox>
#include <QLineEdit>
#include <QGridLayout>
#include "../AlanTwoButtonDialog.h"
#include "../../../../res/img/generic_paths.h"
#include "../../../State/WindowStates/AlanTwoButtonsDialogState/AlanTwoButtonsDialogState.h"
#include "../../../State/WindowStates/AlanTwoButtonsDialogState/ChildStates/SetResolutionDialogState.h"
#include "../../../State/WindowStates/AlanTwoButtonsDialogState/ChildStates/SetLatencyDialogState.h"
#include "../../../../Supplier/OptionSupplier/OptionSupplier.h"
#include "../../../../res/generic_text/Dialogs/AlanTwoButtonDialog/ChildDialogs/SetLatencyDialogText.h"

class SetLatencyDialog : public AlanTwoButtonDialog{
public:
    SetLatencyDialog(AlanTwoButtonsDialogState *state,OptionSupplier *supplier):
            AlanTwoButtonDialog(state,LATENCY_DIALOG_TITLE,LATENCY_ICON),
            rtspClientOptionSupplier(supplier){}
    virtual ~SetLatencyDialog(){
        delete rtspClientOptionSupplier;
    }

private:
    QLineEdit *input;
    OptionSupplier*rtspClientOptionSupplier;
    QWidget *onGenerateConfigArea() throw (std::exception)override {
        QWidget*widget=new QWidget;
        QHBoxLayout*lay;
        widget->setLayout(lay=new QHBoxLayout);
        lay->addWidget(input=new QLineEdit);
        lay->addWidget(new QLabel(SET_LATENCY_DIALOG_MEASUREMENT_UNIT_QLABEL));
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
                input->text().toInt(),
                time(NULL),
                getRtspClientOptionSupplier()));
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
