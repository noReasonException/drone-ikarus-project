//
// Created by noreasonexception on 4/10/18.
//

#ifndef IKARUS_PROJECT_ALANMULTIPLECHOICEDIALOGSTATE_H
#define IKARUS_PROJECT_ALANMULTIPLECHOICEDIALOGSTATE_H


#include "../../../../../InformationObject/Log/Log.h"
#include "../AlanTwoButtonsDialogState.h"
#include <QSettings>
class AlanMultipleChoiceDialogState: public AlanTwoButtonsDialogState{
public:
    static std::vector<QString> staticchoices;
    std::vector<QString> choices;
    AlanMultipleChoiceDialogState()= default;

    virtual ~AlanMultipleChoiceDialogState() = default;
    void update() override {
        AlanTwoButtonsDialogState::update();
        std::cout<<createPath().toStdString()<<std::endl;

        settings->beginWriteArray(createPath()+MULTIPLE_CHOICES_STATE);
        for (int i = 0; i < choices.size(); ++i) {
            settings->setArrayIndex(i);
            settings->setValue(MULTIPLE_STATE_AT_INDEX,choices[i]);
        }
        settings->endArray();
        settings->sync();

    }

    void load() override {
        AlanTwoButtonsDialogState::load();
        std::cout<<createPath().toStdString()<<std::endl;
        for (int i = 0; i < settings->beginReadArray(createPath()+MULTIPLE_CHOICES_STATE); ++i) {
            settings->setArrayIndex(i);
            choices.push_back(settings->value(MULTIPLE_STATE_AT_INDEX).toString());
        }
        settings->endArray();
        settings->sync();
    }

    QString createPath() override {
        return AlanTwoButtonsDialogState::createPath()+MULTIPLE_CHOICE_DIALOG_STATE_PATH;
    }
};

#endif //IKARUS_PROJECT_ALANMULTIPLECHOICEDIALOGSTATE_H
