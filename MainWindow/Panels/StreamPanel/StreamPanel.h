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
    bool generic_initializer() override;            ///the generic initializer, overrider from AlanPanel
    StreamPanel(const QString &title);

    virtual bool initializeListView();              ///@returns true if the initialization step of QListView was successful
    virtual bool initializeSlots();
    virtual QListWidget *onGenerateListView();      ///intializes and @returns the QListView object , needed for initialization

    QListWidget *getListView() const;

private:
    QListWidget*listView;
    static StreamPanel*instance;                    ///Saved instance of siglenton
private slots:
    virtual void onDataClicked(QListWidgetItem *);
public:
    static StreamPanel*getInstance(QString title);  ///Siglenton over StreamPanel


};


#endif //IKARUS_PROJECT_STREAMPANEL_H
