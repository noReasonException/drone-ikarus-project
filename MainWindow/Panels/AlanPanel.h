//
// Created by noreasonexception on 4/3/18.
//

#ifndef IKARUS_PROJECT_ALANPANEL_H
#define IKARUS_PROJECT_ALANPANEL_H


#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QVBoxLayout>
/****
 * AlanPanel represents an abstract panel to exist in AlanMainWindow .
 * Panels exists in two flavors , Stream panels ( a panel witch is a stream , that means that
 * the data witch enter in panel , will never change , for example LogPanel or DataPanel)
 * and StaticPanels (a panel that the view data is fixed and changes, for example a
 * Telemetry panel (not implemented yet //TODO telemetry panel))
 *
 */
class AlanPanel : public QWidget{
    Q_OBJECT;


protected:
    QVBoxLayout*mainLayout;
    QWidget *titleArea;
    QString  title;
    AlanPanel(QString str);

    virtual bool generic_initializer();                     ///@returns true if every initialization step was successful
    virtual bool initializeLayout();                        ///@returns true if the initialization of layout was successful
    virtual bool initializeTitleArea();                     ///@returns true if the title area initialization was successful


    QWidget*    onGenerateTitleArea() throw(std::exception);///@returns a new QWidget designed to be the title area of the panel
    QVBoxLayout*onGenerateLayout()throw(std::exception);    ///@returns the layout designed to be the panels main layout



};


#endif //IKARUS_PROJECT_ALANPANEL_H
