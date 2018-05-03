//
// Created by noreasonexception on 4/3/18.
//

#ifndef IKARUS_PROJECT_STREAMPANEL_H
#define IKARUS_PROJECT_STREAMPANEL_H


#include "../AlanPanel.h"
#include <QObject>
#include <QListView>
#include <QListWidget>
class StreamPanel : public AlanPanel{
    Q_OBJECT
protected:
    StreamPanel(const QString &title);

    ///Initializers/...
    virtual bool generic_initializer() override;            ///the generic initializer, overrider from AlanPanel
    virtual bool initializeListView();              ///@returns true if the initialization step of QListView was successful
    virtual bool initializeSlots();

    ///User-to-Override methods..
    virtual QListWidget *onGenerateListView();      ///intializes and @returns the QListView object , needed for initialization
    QListWidget *getListView() const;

private:
    QListWidget*listView;                           ///TODO in later version , use a custom QListView instead..
private slots:
    virtual void onDataClicked(QListWidgetItem *)=0;

};


#endif //IKARUS_PROJECT_STREAMPANEL_H
