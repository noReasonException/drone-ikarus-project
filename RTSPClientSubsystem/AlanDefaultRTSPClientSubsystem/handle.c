//
// Created by noreasonexception on 4/15/18.
//

#include <glib.h>
#include <glib/gtypes.h>
#include <gst/gstpad.h>
#include <gst/gstelement.h>
#define recallMe return TRUE

extern void on_pad_added_rtspsrc_listener(GstElement*obj, GstPad*arg0, gpointer queue_element){
    g_print("RTSPSRC LISTENER CALLED");
    GstElement*queue_ref=GST_ELEMENT(queue_element);
    GstPad*pad=gst_element_get_static_pad(queue_ref,"sink");
    if(gst_pad_link(arg0,pad)==GST_PAD_LINK_OK){g_print("STREAM CONNECTED TO QUEUE");}
    else{g_print("ERR ON QUEUE");}


    //TODO proper error handling...


}
extern void on_pad_added_decodebin_listener(GstElement*obj,GstPad*arg0,gpointer videoconvert){
    g_print("DECODEBIN LISTENER CALLED");

    GstPad *pad = gst_element_get_static_pad(GST_ELEMENT(videoconvert),"sink");
    if(gst_pad_link(arg0,pad)==GST_PAD_LINK_OK)g_print("DECODEBIN CONNECTED TO VIDEOCONVERT\n");
    else{g_print("ERR ON DECODEBIN->VIDEOCONVERT\n");}
    //TODO proper error handling...


}
/***
 * generic_bus_handler
 * Handles the messages appear on the bus , on any critical error , panic() is called
 *
 * @Note the extern "C" extension exists to avoid name mangling and in incompatibilities with c++ , the
 * gstreamer is originally designed and written in C , avoiding the problem is typically a solution , right?
 *
 * @param bus           The GstBus taken from main pipeline
 * @param msg           The message appeared
 * @param pipeline      The main pipeline
 * @return              **handled by @see_macro recallme , simply returns true , if not , this handler will be
 *                      dismissed
 */
extern gboolean  generic_bus_handler(GstBus *bus, GstMessage *msg, gpointer pipeline){

    switch (GST_MESSAGE_TYPE(msg)){
        case GST_MESSAGE_ERROR:{
            GError*err;
            gchar *debug;
            gst_message_parse_error(msg,&err,&debug);
            g_print("%s",debug);
        }


    }
    const gchar *err= gst_message_type_get_name(msg->type);
    g_print("%s\n?",err);
    recallMe;
}
GstPadProbeReturn on_timestamp_export_probe_triggered(GstPad *pad, GstPadProbeInfo *info,
                                                      gpointer user_data) {
    GstMapInfo map;
    GstBuffer *buff = gst_buffer_make_writable(GST_PAD_PROBE_INFO_BUFFER(info));

    if(gst_buffer_map(buff,&map,GST_MAP_READ)){
        g_print("0x%08x with size %d and idx=%d\t",*(map.data+48),map.size,gst_buffer_n_memory(buff));
        g_print("0x%08x with size %d and idx=%d\t",*(map.data+49),map.size,gst_buffer_n_memory(buff));
        g_print("0x%08x with size %d and idx=%d\t",*(map.data+50),map.size,gst_buffer_n_memory(buff));
        g_print("0x%08x with size %d and idx=%d\n",*(map.data+51),map.size,gst_buffer_n_memory(buff));

        gst_buffer_unmap(buff,&map);
    }
    GST_PAD_PROBE_INFO_DATA (info) = buff;


    return GST_PAD_PROBE_OK;

}