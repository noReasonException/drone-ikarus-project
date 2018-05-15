/*
 * Copyright (C) 2018 Stefanos Stefanou
 * This file is part of AlanStreamer.

    AlanStreamer is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    AlanStreamer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.


    You should have received a copy of the GNU General Public License
    along with AlanStreamer.  If not, see <http://www.gnu.org/licenses/>.

 */
#ifndef IKARUS_PROJECT_ALANMULTIPLECHOICEDIALOGSTATE_H
#define IKARUS_PROJECT_ALANMULTIPLECHOICEDIALOGSTATE_H


#include "../../../../../InformationObject/Log/Log.h"
#include "../AlanTwoButtonsDialogState.h"
#include <QSettings>
class AlanMultipleChoiceDialogState: public AlanTwoButtonsDialogState{
public:
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
