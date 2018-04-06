//
// Created by noreasonexception on 4/6/18.
//

#ifndef IKARUS_PROJECT_ALANTWOBUTTONDIALOG_H
#define IKARUS_PROJECT_ALANTWOBUTTONDIALOG_H


#include "../AlanSingleOptionDialog.h"

class AlanTwoButtonDialog: public AlanSingleOptionDialog {
public:
    AlanTwoButtonDialog(const QString );
public:
    static AlanTwoButtonDialog*getInstance(const QString &);

protected:
    QWidget *onGenerateIconArea() override;

    QWidget *onGenerateTitleArea() override;

    QWidget *onGenerateConfigArea() override;

    QWidget *onGenerateButtonsArea() override;
};


#endif //IKARUS_PROJECT_ALANTWOBUTTONDIALOG_H
