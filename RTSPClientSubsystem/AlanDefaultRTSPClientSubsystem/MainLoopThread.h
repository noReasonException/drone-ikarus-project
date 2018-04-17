//
// Created by noreasonexception on 4/18/18.
//

#ifndef IKARUS_PROJECT_MAINLOOPTHREAD_H
#define IKARUS_PROJECT_MAINLOOPTHREAD_H


#include <QThread>
#include <glib.h>

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
