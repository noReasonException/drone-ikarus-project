//
// Created by noreasonexception on 4/14/18.
//

#ifndef IKARUS_PROJECT_ALANDEFAULTRTSPCLIENTSUBSYSTEM_H
#define IKARUS_PROJECT_ALANDEFAULTRTSPCLIENTSUBSYSTEM_H


#include <QSettings>
#include <gst/gstelementfactory.h>
#include "../AbstractRTSPClientSubsystem.h"
#include "qsettings.h"

class AlanDefaultRTSPClientSubsystem: public AbstractRTSPClientSubsystem {

private :
    QSettings settings;
    bool isNullThenLog(void *ptr, const QString &onErrorMessage);
    bool logSuccess(void *ptr, const QString &message);
    bool isWindowHandleDefined=false;
    bool isClientStatusDefined=false;
public:
    AlanDefaultRTSPClientSubsystem();

private:
    ClientStatus currentStatus;
    int windowHandle;
    guint   major,
            minor,
            nano,
            pico,
            bus_handler_watch_id;

    GstElementFactory
            *gstrtspsrc_fact,
            *queue_fact,
            *rtph264depayloader_fact,
            *decodebin_fact,
            *videoconvert_fact,
            *ximagesink_fact;
    GstElement
            *pipeline,
            *gstrtspsrc_elem,
            *queue_elem,
            *rtph264depayloader,
            *decodebin_elem,
            *videoconvert_elem,
            *ximagessink_elem;

    GMainLoop   *mainLoop;
    GstBus      *mainBus;

protected:
    bool onLatencySettingChangedHandler(class LatencyOption *) override;

    bool onResolutionSettingChangedHandler(class ResolutionOption *) override;

    bool onClientStatusSettingChangedHandler(class ClientStatusOption *) override;

    bool onWindowHandlerSettingChangedHandler(class WindowHandleOption *) override;

    bool onLocationSettingChangedHandler(class LocationOption *option) override;

    virtual bool callProperStatusHandler();
    virtual bool onStartStatusRequest();
    virtual bool onPlayStatusRequest();
    virtual bool onPauseStatusRequest();
    virtual bool onStopStatusRequest();


};


#endif //IKARUS_PROJECT_ALANDEFAULTRTSPCLIENTSUBSYSTEM_H
