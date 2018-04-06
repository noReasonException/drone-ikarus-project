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
    ///TODO:fix leak on getInstance
    static AlanTwoButtonDialog*getInstance(const QString &,const QString&);

protected:

    virtual bool generic_initializer() override ;
    virtual bool connectionInitializer();


    QWidget *onGenerateConfigArea() throw (std::exception)override;

    QWidget *onGenerateButtonsArea() throw(std::exception)override;

protected slots:
    virtual void onOkButtonSlot();
    virtual void onCancelButtonSlot();


};


#endif //IKARUS_PROJECT_ALANTWOBUTTONDIALOG_H
