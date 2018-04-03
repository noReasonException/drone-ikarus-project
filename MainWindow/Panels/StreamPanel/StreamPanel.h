//
// Created by noreasonexception on 4/3/18.
//

#ifndef IKARUS_PROJECT_STREAMPANEL_H
#define IKARUS_PROJECT_STREAMPANEL_H


#include "../AlanPanel.h"
#include <QObject>
#include <QListView>

class StreamPanel : public AlanPanel{
    Q_OBJECT
public:
    StreamPanel();

private:
    QListView *dataView;
    bool    initializeDataView();
    virtual bool generic_initializer() override ;

protected:
    QListView *onGenerateDataView();
};


#endif //IKARUS_PROJECT_STREAMPANEL_H
