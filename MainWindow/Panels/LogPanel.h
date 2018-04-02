//
// Created by noreasonexception on 4/2/18.
//

#ifndef IKARUS_PROJECT_LOGPANEL_H
#define IKARUS_PROJECT_LOGPANEL_H


#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class LogPanel:public QWidget {
    Q_OBJECT
public:
    QLabel *titleLabel;
    QVBoxLayout *main_lay;


    LogPanel();

private:
    bool generic_initializer();
    bool initializeLayout();
    bool initializeTitleWidget();
    bool initializeLogWidgets();


protected:
    QWidget *onGenerateTitleWidget();

};


#endif //IKARUS_PROJECT_LOGPANEL_H
