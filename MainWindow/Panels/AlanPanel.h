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
    AlanPanel();


private:
    QWidget *titleArea;

    bool initializeTitleArea();


protected:
    virtual bool generic_initializer();

    virtual QWidget*    onGenerateTitleArea() throw(std::exception)=0;



};


#endif //IKARUS_PROJECT_ALANPANEL_H
