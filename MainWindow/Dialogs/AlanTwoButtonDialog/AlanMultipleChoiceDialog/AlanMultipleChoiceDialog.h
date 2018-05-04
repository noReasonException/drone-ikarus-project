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
#include "../../../../res/img/generic_paths.h"
#include "../../../State/WindowStates/AlanTwoButtonsDialogState/AlanMultipleChoiceDialogState/AlanMultipleChoiceDialogState.h"

class AlanMultipleChoiceDialog: public AlanTwoButtonDialog{
    Q_OBJECT
private:
    const QString pushButtonText;

    QPushButton*additionalButton;

protected:
    QLineEdit*lineEdit;
    QListWidget*listWidget;
    AlanMultipleChoiceDialog(AlanMultipleChoiceDialogState* state,const QString &title,const QString&icon,const QString&buttonText) :
            AlanTwoButtonDialog(state,title,icon),
            pushButtonText(buttonText){}
    virtual ~AlanMultipleChoiceDialog()= default;


    ///New additional initialization steps...
    virtual bool additionalButtonsInitializer();



    ///Override previous stuff + override generic_initializer to initialize this new functionality
    AlanMultipleChoiceDialogState* onRestoreState() throw(std::exception) override;

    AlanMultipleChoiceDialogState *onSaveState() throw(std::exception) override;

    QWidget *onGenerateConfigArea() throw (std::exception)override;
    virtual bool generic_initializer()override ;

protected slots:



    virtual void onAdditionalButtonSlot()=0;

    virtual void onClickedChoiceSlot(QListWidgetItem*)=0;


};
#endif //IKARUS_PROJECT_ALANRESOLUTIONDIALOG_H
