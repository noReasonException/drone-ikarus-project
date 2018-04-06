//
// Created by noreasonexception on 4/6/18.
//

#ifndef IKARUS_PROJECT_ALANTWOBUTTONDIALOG_H
#define IKARUS_PROJECT_ALANTWOBUTTONDIALOG_H


#include "../AlanSingleOptionDialog.h"

class AlanTwoButtonDialog: public AlanSingleOptionDialog {
    Q_OBJECT
private:
    QPushButton *okBtn;
    QPushButton *cancelBtn;
public:
    AlanTwoButtonDialog(const QString&,const QString &icon );

protected:

    bool generic_initializer() override ;
    virtual bool connectionInitializer();




    QWidget *onGenerateButtonsArea() throw(std::exception)override;

protected slots:
    virtual void onOkButtonSlot()=0;
    virtual void onCancelButtonSlot()=0;


};


#endif //IKARUS_PROJECT_ALANTWOBUTTONDIALOG_H