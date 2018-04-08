//
// Created by noreasonexception on 4/8/18.
//

#ifndef IKARUS_PROJECT_SETLATENCYDIALOG_H
#define IKARUS_PROJECT_SETLATENCYDIALOG_H


#include <QMessageBox>
#include <QLineEdit>
#include <QGridLayout>
#include "../AlanTwoButtonDialog.h"
#include "../../../../misc/img/generic_paths.h"

class SetLatencyDialog : public AlanTwoButtonDialog{
public:
    SetLatencyDialog(AlanTwoButtonsDialogState *state):AlanTwoButtonDialog(state,"Set Video Resolution",LATENCY_ICON){}

private:
    QWidget *onGenerateConfigArea() throw (std::exception)override {
        QWidget*widget=new QWidget;
        QHBoxLayout*lay;
        widget->setLayout(lay=new QHBoxLayout);
        lay->addWidget(new QLineEdit);
        lay->addWidget(new QLabel("ms"));
        return widget;


    }

    void onOkButtonSlot() override {
        QMessageBox::warning(nullptr,"aaaaa","aa");
    }

    void onCancelButtonSlot() override {

    }
};


#endif //IKARUS_PROJECT_SETLATENCYDIALOG_H
