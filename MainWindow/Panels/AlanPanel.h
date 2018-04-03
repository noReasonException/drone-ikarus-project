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

    AlanPanel(QWidget *parent, const Qt::WindowFlags &f);

private:
    QWidget *titleArea;
    QWidget *panelArea;

    bool generic_initializer();
    bool initializeTitleArea();
    bool initializePanelArea();

protected:

    virtual QWidget*    onGenerateTitleArea() throw(std::exception)=0;
    virtual QWidget*    onGeneratePanelArea() throw(std::exception)=0;



};


#endif //IKARUS_PROJECT_ALANPANEL_H
