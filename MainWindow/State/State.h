//
// Created by noreasonexception on 4/5/18.
//

#ifndef IKARUS_PROJECT_STATE_H
#define IKARUS_PROJECT_STATE_H

#include <QSettings>
#include <QString>
#include <QtWidgets/QDialog>
#include <iostream>
#include "../Panels/StreamPanel/LogPanel/LogPanel.h"
#include "../../res/Suppliers/LogSuppliers.h"
/***
 * State class
 * Every dialog saves its internal state in one of his State-derived object , this parallel hierarchy restores
 * every dialog to his previous state . when you want to implement a new dialog , you need to implement
 * also his State class
 * for example
 * for SetServersAddrDialog class , there are a par SetServersAddrDialogState object , witch knows how to restore
 * the dialog to its previous state
 * the SetServersAddrDialogState follows simmilar hierarchy as SetServersAddrDialog
 *
 * SetServersAddrDialog(F)          SetServersAddrDialogState
 *          |                                   |
 * AlanMultipleChoiceDialog         AlanMultipleChoiceDialogState
 *          |                                   |
 * AlanTwoButtonDialog              AlanTwoButtonDialogState
 *          |                                   |
 * AlanSingleOptionDialog           AlanSingleOptionDialogState
 *                                              |
 *                                            State
 * Every Final class (Dialog that cannot be extended more) has the responsibillity of calling the restoring procedures
 * every dialog has the responsibillity to restore only the features he provides , everything else is take care by \
 * parent classes
 * The actual State class is nothing more than a wrapper over QSettings class @see doc.qt.io/qt-5/qsettings.html
 */
class State {
public:
    State();

    /***
     * The createPath method , creates the string will be used in Qsettings::setValue() as unique prefix
     * for example , the AlanMultipleChoiceDialog class , will have in every key in key-value pairs
     * of himself , a standard prefix /SINGLEOPTION/TWOBUTTONS/MULTIPLECHOICE/ ...
     * @note Every derived class , has the responsibillity to override this method , and returns whatever
     * the parent method returns + a standard class prefix , defined in misc/states.h
     * for example , the AlanTwoButtonDialogState version of .createPath() is..
     *              QString createPath() override {
     *                   return AlanSingleOptionDialogState::createPath()+TWO_BUTTONS_DIALOG_STATE_PATH;
     *              }
     * @return a standard prefix for use
     */
    virtual QString createPath()=0;
    /****
     * .update()
     * The .update() method 'saves' the actual data into hard drive , when .update() returns , it is guaranteed
     * that all data is saved every buffer is flused
     * @Note Every derived class has the responsibillity to call his parent first
     *
     */
    virtual void update()=0;
    /***
     * .load()
     * The .load() restores the data from the hard drive
     * @Note Every derived class has the responsibillity to call his parent first
     */
    virtual void load()=0;
    /***
     * The actual QSettings!
     * @note why not static? QSettings has some problems when declared with static lifetime
     */
    QSettings *settings;


};


#endif //IKARUS_PROJECT_STATE_H
