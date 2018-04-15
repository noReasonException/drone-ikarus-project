//
// Created by noreasonexception on 4/14/18.
//

#ifndef IKARUS_PROJECT_ALANDEFAULTRTSPCLIENTSUBSYSTEM_H
#define IKARUS_PROJECT_ALANDEFAULTRTSPCLIENTSUBSYSTEM_H


#include <QSettings>
#include <glib/gtypes.h>
#include <gst/gstelementfactory.h>
#include "../AbstractRTSPClientSubsystem.h"
#include "qsettings.h"

class AlanDefaultRTSPClientSubsystem: public AbstractRTSPClientSubsystem {

private :
    QSettings settings;
    bool isNull(void *ptr, const QString &onErrorMessage,const QString &onSuccessMessage);
    bool isWindowHandleDefined=false;
    bool isClientStatusDefined=false;
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
    void onLatencySettingChangedHandler(class LatencyOption *) override;

    void onResolutionSettingChangedHandler(class ResolutionOption *) override;

    void onClientStatusSettingChangedHandler(class ClientStatusOption *) override;

    void onWindowHandlerSettingChangedHandler(class WindowHandleOption *) override;

    void onLocationSettingChangedHandler(class LocationOption *option) override;
};


#endif //IKARUS_PROJECT_ALANDEFAULTRTSPCLIENTSUBSYSTEM_H
