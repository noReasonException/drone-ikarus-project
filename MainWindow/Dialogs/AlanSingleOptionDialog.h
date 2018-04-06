//
// Created by noreasonexception on 4/5/18.
//

#ifndef IKARUS_PROJECT_ALANSINGLEOPTIONDIALOG_H
#define IKARUS_PROJECT_ALANSINGLEOPTIONDIALOG_H


#include <QDialog>

class AlanSingleOptionDialog : public QDialog{
    Q_OBJECT
private:
    QLayout*mainLay;
    QString titleArea;
    QString iconArea;



protected:
    AlanSingleOptionDialog(const QString&,const QString&);
    virtual bool generic_initializer();                     ///@returns true if all initialization processes completed
    virtual bool layoutInitializer();                       ///@returns true if layout initialization process completed


    virtual QLayout*onGenerateLayout() throw(std::exception);                     ///@returns the AlanSingleOptionDialog layout
    virtual QWidget*onGenerateIconArea() throw (std::exception);                   ///@returns the left icon Area Widget
    virtual QWidget*onGenerateTitleArea() throw (std::exception);                  ///@returns the right-top title area
    virtual QWidget*onGenerateConfigArea() throw (std::exception)=0;                 ///@returns the right-center actual configuration area
    virtual QWidget*onGenerateButtonsArea() throw (std::exception)=0;                ///@returns the right-bottom button area
    virtual QWidget*onGenerateLeftmostArea() throw (std::exception);
    virtual QWidget*onGenerateRightMostArea() throw (std::exception);




};


#endif //IKARUS_PROJECT_ALANSINGLEOPTIONDIALOG_H
