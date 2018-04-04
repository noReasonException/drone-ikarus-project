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
    bool generic_initializer() override;
    StreamPanel(const QString &str);

    virtual bool initializeListView();
    virtual QListView *onGenerateListView();
private:
    QListView*listView;
    static StreamPanel*instance;
public:
    static StreamPanel*getInstance(QString title);


};


#endif //IKARUS_PROJECT_STREAMPANEL_H
