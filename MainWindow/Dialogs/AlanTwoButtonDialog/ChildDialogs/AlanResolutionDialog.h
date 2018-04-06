//
// Created by noreasonexception on 4/6/18.
//

#ifndef IKARUS_PROJECT_ALANRESOLUTIONDIALOG_H
#define IKARUS_PROJECT_ALANRESOLUTIONDIALOG_H

#include <QtWidgets/QMessageBox>
#include <QLabel>
#include "../AlanTwoButtonDialog.h"
#include "../../../../misc/img/generic_paths.h"

class AlanResolutionDialog: public AlanTwoButtonDialog{
    Q_OBJECT

public:
    ///TODO:fix leak on getInstance
    ////TODO::error: ‘virtual bool AlanTwoButtonDialog::generic_initializer()’ is protected within this context ptr->generic_initializer();*/
    static AlanTwoButtonDialog*getInstance(){
        AlanResolutionDialog*ptr=new AlanResolutionDialog();
        ptr->generic_initializer();
        return ptr;
    };
protected:
    AlanResolutionDialog() : AlanTwoButtonDialog("Set Video Resolution",RESOLUTION_ICON){}

    QWidget *onGenerateConfigArea() throw (std::exception)override{
        return new QLabel("Hey");
    }


protected slots:

    void onOkButtonSlot() override {
        QMessageBox::warning(nullptr,"he","he");
    }

    void onCancelButtonSlot() override {
        return;
    }

};
#endif //IKARUS_PROJECT_ALANRESOLUTIONDIALOG_H
