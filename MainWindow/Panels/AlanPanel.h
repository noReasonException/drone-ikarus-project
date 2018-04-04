//
// Created by noreasonexception on 4/3/18.
//

#ifndef IKARUS_PROJECT_ALANPANEL_H
#define IKARUS_PROJECT_ALANPANEL_H


#include <QWidget>
#include <QObject>
#include <QLabel>

class AlanPanel : public QWidget{
    Q_OBJECT;
public:

    static AlanPanel*getInstance(QString title);



private:
    AlanPanel(QString str);
    AlanPanel()= default;
    QLayout*mainLayout;
    QWidget *titleArea;
    QString  title;
    static AlanPanel*instance;


protected:
    virtual bool generic_initializer();
    virtual bool initializeLayout();
    virtual bool initializeTitleArea();


    QWidget*    onGenerateTitleArea() throw(std::exception);



};


#endif //IKARUS_PROJECT_ALANPANEL_H
