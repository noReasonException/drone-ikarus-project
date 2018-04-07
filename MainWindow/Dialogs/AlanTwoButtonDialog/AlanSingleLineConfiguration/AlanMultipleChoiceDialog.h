//
// Created by noreasonexception on 4/6/18.
//

#ifndef IKARUS_PROJECT_ALANRESOLUTIONDIALOG_H
#define IKARUS_PROJECT_ALANRESOLUTIONDIALOG_H

#include <QMessageBox>
#include <QLayout>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include "../AlanTwoButtonDialog.h"
#include "../../../../misc/img/generic_paths.h"

class AlanMultipleChoiceDialog: public AlanTwoButtonDialog{
    Q_OBJECT
private:
    const QString pushButtonText;
    QListWidget*listWidget;
    QPushButton*additionalButton;

public:

    ///TODO:fix leak on getInstance
    ////TODO::error: ‘virtual bool AlanTwoButtonDialog::generic_initializer()’ is protected within this context ptr->generic_initializer();*/
    static AlanTwoButtonDialog*getInstance();
protected:
    AlanMultipleChoiceDialog(AlanMultipleChoiceDialogState* state,const QString &title,const QString&icon,const QString&buttonText) :
            AlanTwoButtonDialog(state,title,icon),
            pushButtonText(buttonText){}
    virtual ~AlanMultipleChoiceDialog()= default;


    ///New additional initialization steps...
    virtual bool additionalButtonInitializer();



    ///Override previous stuff + override generic_initializer to initialize this new functionality
    AlanMultipleChoiceDialogState* onRestoreState() throw(std::exception) override;
    QWidget *onGenerateConfigArea() throw (std::exception)override;
    virtual bool generic_initializer()override ;

protected slots:

    void onOkButtonSlot() override ;

    void onCancelButtonSlot() override ;

    virtual void onAdditionalButtonSlot();


};
#endif //IKARUS_PROJECT_ALANRESOLUTIONDIALOG_H
