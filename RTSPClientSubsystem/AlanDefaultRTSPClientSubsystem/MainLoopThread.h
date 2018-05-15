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
#ifndef IKARUS_PROJECT_MAINLOOPTHREAD_H
#define IKARUS_PROJECT_MAINLOOPTHREAD_H


#include <QThread>
#include <glib.h>
/*****
 * Class MainLoopThread
 * This Thread will run the GMainLoop main looper .
 * The code is self-explanatory i think  :P
 */
class MainLoopThread : public QThread{
    GMainLoop*loop;
public:
    MainLoopThread() = default;

private:
Q_OBJECT
    void run() override {
        g_main_loop_run(loop);

        emit interruptedSignal();
    }

public:
    MainLoopThread* setLoop(GMainLoop *loop) {
        MainLoopThread::loop = loop;
        return this;
    }

    GMainLoop *getLoop() const {
        return loop;
    }

private:
signals:
    void interruptedSignal();

};
#endif //IKARUS_PROJECT_MAINLOOPTHREAD_H
