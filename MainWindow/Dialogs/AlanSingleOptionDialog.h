//
// Created by noreasonexception on 4/5/18.
//

#ifndef IKARUS_PROJECT_ALANSINGLEOPTIONDIALOG_H
#define IKARUS_PROJECT_ALANSINGLEOPTIONDIALOG_H


#include <QDialog>

class AlanSingleOptionDialog : public QDialog{
private:
    AlanSingleOptionDialog(QString);

public:
    static AlanSingleOptionDialog*getInstance(QString);

protected:
    virtual bool generic_initializer();
    virtual bool layoutInitializer();
    virtual bool titleAreaInitializer();
    virtual QLayout*onGenerateLayout();
    virtual QWidget* onGenerateTitleArea();

private:
    QString titleAreaText;
public:
    const QString &getTitleAreaText() const;

    void setTitleAreaText(const QString &titleAreaText);
};


#endif //IKARUS_PROJECT_ALANSINGLEOPTIONDIALOG_H
