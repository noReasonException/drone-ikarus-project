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

#ifndef IKARUS_PROJECT_ALANTWOBUTTONDIALOG_H
#define IKARUS_PROJECT_ALANTWOBUTTONDIALOG_H


#include "../AlanSingleOptionDialog.h"
#include "../../State/WindowStates/AlanTwoButtonsDialogState/AlanTwoButtonsDialogState.h"

class AlanTwoButtonDialog: public AlanSingleOptionDialog {
    Q_OBJECT
private:
    QPushButton *okBtn;
    QPushButton *cancelBtn;
public:
    AlanTwoButtonDialog(AlanTwoButtonsDialogState* ,const QString&,const QString &icon );
    virtual ~AlanTwoButtonDialog()= default;

protected:

    bool generic_initializer() override ;
    bool connectionInitializer();
    AlanTwoButtonsDialogState* onRestoreState() throw(std::exception) override;
    AlanTwoButtonsDialogState* onSaveState() throw(std::exception) override;
    QWidget *onGenerateButtonsArea() throw(std::exception)override;

protected slots:
    virtual void onOkButtonSlot();
    virtual void onCancelButtonSlot();



};


#endif //IKARUS_PROJECT_ALANTWOBUTTONDIALOG_H
