//
// Created by noreasonexception on 4/5/18.
//

#ifndef IKARUS_PROJECT_ALANSINGLEOPTIONDIALOG_H
#define IKARUS_PROJECT_ALANSINGLEOPTIONDIALOG_H


#include <QDialog>
#include "../State/WindowStates/AlanSingleOptionDialogState.h"
/****
 * class AlanSingleOptionDialog
 * this class represents an absract Alan dialog
 */
class AlanSingleOptionDialog : public QDialog{
    Q_OBJECT
public:
    virtual AlanSingleOptionDialog*prepare();
private:
    QLayout*mainLay;
    QString titleArea;
    QString iconArea;
    AlanSingleOptionDialogState *state;



protected:
    AlanSingleOptionDialog(AlanSingleOptionDialogState*state,const QString&title,const QString&icon);
    //TODO final here?
    virtual ~AlanSingleOptionDialog()= default;
    virtual bool generic_initializer();                     ///@returns true if all initialization processes completed
    bool layoutInitializer();                       ///@returns true if layout initialization process completed

    virtual QLayout*onGenerateLayout() throw(std::exception);                     ///@returns the AlanSingleOptionDialog layout
    virtual QWidget*onGenerateIconArea() throw (std::exception);                   ///@returns the left icon Area Widget
    virtual QWidget*onGenerateTitleArea() throw (std::exception);                  ///@returns the right-top title area
    virtual QWidget*onGenerateConfigArea() throw (std::exception)=0;                 ///@returns the right-center actual configuration area
    virtual QWidget*onGenerateButtonsArea() throw (std::exception)=0;                ///@returns the right-bottom button area
    virtual QWidget*onGenerateLeftmostArea() throw (std::exception);
    virtual QWidget*onGenerateRightMostArea() throw (std::exception);
    virtual AlanSingleOptionDialogState * onRestoreState() throw(std::exception);
    virtual AlanSingleOptionDialogState * onSaveState() throw(std::exception);
    AlanSingleOptionDialogState *getState() const;




};


#endif //IKARUS_PROJECT_ALANSINGLEOPTIONDIALOG_H
