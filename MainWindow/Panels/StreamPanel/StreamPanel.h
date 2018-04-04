//
// Created by noreasonexception on 4/3/18.
//

#ifndef IKARUS_PROJECT_STREAMPANEL_H
#define IKARUS_PROJECT_STREAMPANEL_H


#include "../AlanPanel.h"
#include <QObject>
#include <QListView>

class StreamPanel : public AlanPanel{
protected:
    bool generic_initializer() override;            ///the generic initializer, overrider from AlanPanel
    StreamPanel(const QString &title);

    virtual bool initializeListView();              ///@returns true if the initialization step of QListView was successful
    virtual QListView *onGenerateListView();        ///intializes and @returns the QListView object , needed for initialization
private:
    QListView*listView;
    static StreamPanel*instance;                    ///Saved instance of siglenton
public:
    static StreamPanel*getInstance(QString title);  ///Siglenton over StreamPanel


};


#endif //IKARUS_PROJECT_STREAMPANEL_H
