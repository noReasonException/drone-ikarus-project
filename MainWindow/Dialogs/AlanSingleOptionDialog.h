//
// Created by noreasonexception on 4/5/18.
//

#ifndef IKARUS_PROJECT_ALANSINGLEOPTIONDIALOG_H
#define IKARUS_PROJECT_ALANSINGLEOPTIONDIALOG_H


#include <QDialog>

class AlanSingleOptionDialog : public QDialog{
private:
    AlanSingleOptionDialog(QString);

public:
    static AlanSingleOptionDialog*getInstance(QString);

protected:
    virtual bool generic_initializer();                     ///@returns true if all initialization processes completed
    virtual bool layoutInitializer();                       ///@returns true if layout initialization process completed

    virtual QLayout*onGenerateLayout();                     ///@returns the AlanSingleOptionDialog layout
    virtual QWidget*onGenerateIconArea();                   ///@returns the left icon Area Widget
    virtual QWidget*onGenerateTitleArea();                  ///@returns the right-top title area
    virtual QWidget*onGenerateConfigArea();                 ///@returns the right-center actual configuration area
    virtual QWidget*onGenerateButtonsArea();                ///@returns the right-bottom button area
    virtual QWidget*onGenerateLeftmostArea();
    virtual QWidget*onGenerateRightMostArea();
///Why protected setters-getters? only the derived classes can have access to mainLay/titleArea,not   client!
    QLayout *getMainLay() const;

    void setMainLay(QLayout *mainLay);

    QString *getTitleArea() const;

    void setTitleArea(QString *titleArea);
private:
    QLayout*mainLay;
    QString*titleArea;


};


#endif //IKARUS_PROJECT_ALANSINGLEOPTIONDIALOG_H
