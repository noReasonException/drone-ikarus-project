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

class AlanResolutionDialog: public AlanTwoButtonDialog{
    Q_OBJECT

public:
    const QString pushButtonText;
    ///TODO:fix leak on getInstance
    ////TODO::error: ‘virtual bool AlanTwoButtonDialog::generic_initializer()’ is protected within this context ptr->generic_initializer();*/
    static AlanTwoButtonDialog*getInstance(){
        AlanResolutionDialog*ptr=new AlanResolutionDialog("Add New...");
        ptr->generic_initializer();
        return ptr;
    };
protected:
    AlanResolutionDialog(const QString&buttonText) : AlanTwoButtonDialog("Set Video Resolution",RESOLUTION_ICON),pushButtonText(buttonText){}

    QWidget *onGenerateConfigArea() throw (std::exception)override{

        QWidget*widget=new QWidget();                       //Main Config Widget
        QWidget*newData=new QWidget();                      //Add new data subwidget
        QLayout*lay=new QVBoxLayout();                      //Setup Layout;
        QLayout*newData_Layout=new QHBoxLayout;


        widget->setLayout(lay);                             //Pass Layouts
        newData->setLayout(newData_Layout);

        lay->addWidget(new QListWidget);                    //Add QListWidget in Config Area
        newData_Layout->addWidget(new QLineEdit);
        newData_Layout->addWidget(new QPushButton(pushButtonText));
        lay->addWidget(newData);                            //Add new configuration in bottom of config area
        return widget;
    }


protected slots:

    void onOkButtonSlot() override {
        QMessageBox::warning(nullptr,"he","he");
    }

    void onCancelButtonSlot() override {
        return;
    }

};
#endif //IKARUS_PROJECT_ALANRESOLUTIONDIALOG_H
