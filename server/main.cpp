/****
* Main Server (Transmitter) File
        * Uses * wrappercamerabinsrc   (camera to raw video)   (**         ->video/raw)
*       * x264enc               (H264 Encoder)          (video/raw  ->video/h264)
*       * rtph264pay            (H264 to RTP Packets)   (video/h264 ->application/rtp)
*          And a RTP-RTSP Server to send the frames to the client
*
*/

#include <gst/gstdebugutils.h>
#include <gst/gst.h>
#include <gst/rtsp-server/rtsp-server.h>
#include <gst/app/gstappsrc.h>
#include <gst/rtsp/gstrtspurl.h>
#include <glib.h>
#include <stdarg.h>
#include <stdlib.h>
#include <iostream>
#include <gst/gstmemory.h>
#include "server.h"
void on_enough_data_listener (GstElement* object,
                              gpointer user_data){
    g_print("ENOUGH\n");
}

void on_need_data_listener(GstElement *object,
                           guint arg0,
                           gpointer user_data){
    g_print("NEED\n");
    int ret;
    g_signal_emit_by_name (GST_APP_SRC(object), "push-buffer", gst_buffer_new(), &ret);

}


void media_factory(GstRTSPMediaFactory * factory, GstRTSPMedia * media,
                   gpointer user_data)

{
    GstElement *element, *appsrc;

    /* get the element used for providing the streams of the media */
    element = gst_rtsp_media_get_element (media);

    /* get our appsrc, we named it 'mysrc' with the name property */
    appsrc = gst_bin_get_by_name_recurse_up (GST_BIN (element), "srca");

    /* this instructs appsrc that we will be dealing with timed buffer */
    g_object_set (G_OBJECT (appsrc), "format", GST_FORMAT_UNDEFINED);
    /* configure the caps of the video */
    g_object_set (G_OBJECT (appsrc), "caps",
                  gst_caps_new_simple ("application/x-rtp",NULL), NULL);


    /* make sure ther datais freed when the media is gone */
    g_object_set_data_full (G_OBJECT (media), "my-extra-data", NULL,
                            (GDestroyNotify) g_free);

    /* install the callback that will be called when a buffer is needed */
    g_signal_connect (appsrc, "need-data", (GCallback) on_need_data_listener, NULL);
    g_signal_connect (appsrc, "enough-data", (GCallback) on_enough_data_listener, NULL);
    gst_object_unref (appsrc);
    gst_object_unref (element);
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
extern "C" gboolean  generic_bus_handler(GstBus *bus, GstMessage *msg, gpointer pipeline){

    g_print("called\n");
    const gchar *err= gst_message_type_get_name(msg->type);
    gst_element_set_state((GstElement*)pipeline,GST_STATE_PLAYING);
    g_print("%s",err);
    recallMe;
}
/***
 * generic_initializer
 * @param flags a combination of macros beginning with GIN_*
 * @param num   the number of pairs *(see note below!)
 * @param ...   the parameter pairs
 * @return      TRUE if the operation succeded
 * @Note
 * in case you want to initialize factories(GIN_INITIALIZE_TYPE_FACTORY) , then the ... parameter
 * expects num times the pattern...
 *                          (**GstElementFactory,"name_in_string")
 * in case you want to initialize elements(GIN_INITIALIZE_TYPE_FACTORY) , then the .. parameter
 * expects num times the pattern...
 *                          (*GstElementFactory,**GstElement,"name_in_string")
 * The GIN_FREE_STRING_AFTER used to release the string name , in case of parsing it with g_strdup
 *
 */
static gboolean generic_initializer(const int flags, int num, ...){
    GstElementFactory	**cursor;
    GstElementFactory	*temp_fact;
    GstElement       	**temp_elem;
    gchar 			* name;
    gboolean 		stop=FALSE;
    va_list args;
    va_start(args,num);
    while(num>0){
        num-=1;
        if(flags&GIN_INITIALIZE_TYPE_FACTORY){
            cursor=va_arg(args,GstElementFactory**);
            name=va_arg(args,gchar *);
            *cursor=gst_element_factory_find(name);
            if(!(*cursor)){
                g_print("[INFO] %s factory not found!",name);
                stop=TRUE;
                break;
            }
            g_print("[INFO] %s factory loaded\n",name);
        }
        else if(flags&GIN_INITIALIZE_TYPE_ELEMENT){
            temp_fact=(GstElementFactory*)va_arg(args,GstElementFactory*);
            temp_elem=(GstElement**)va_arg(args,GstElement**);
            name=(gchar*)va_arg(args,gchar*);
            *temp_elem=gst_element_factory_create(temp_fact,name);
            if(!(*temp_elem)){
                g_print("[ERR] %s not loaded!\n",name);
                stop=TRUE;
                break;
            }
            g_print("![INFO] %s element loaded\n",name);
        }
    }
    if(flags&GIN_FREE_STRING_AFTER) g_free(name);
    if(stop)return FALSE;
    return TRUE;
}
/***
 * static_urls_alloc , creates the initial static empty table with urls
 * @Note for now , only one url exists , the /str (VIDEO_ADDR). but in future
 * the function complex(static_urls_alloc/url_alloc/get_url_instance)
 * will adjust the program much more easily to new streams!
 * @return a fresh new one GstRTSPUrl's !
 */
GstRTSPUrl ** static_urls_alloc(){
    GstRTSPUrl**url = (GstRTSPUrl**)malloc(sizeof(GstRTSPUrl*)*NUM_ADDR);
    for (int i = 0; i < NUM_ADDR - 1; ++i) {
        url[i]=NULL;
    }
    return url;
}
/***
 * url_alloc , creates a url just in time the @see get_url_instance() ask for it .
 * @param loc , the location the object will be initialized
 * @param flag ,the context of url
 *          for example
 *              url_alloc(&loc,VIDEO_ADDR_INDEX) -> will initialize the url with address rtsp://127.0.0.1:8000/str
 *              , the video streaming address!
 *          The flag parameter ,untill now(server version 0.0.1) takes only one possible value , INDEX_ADDR_VIDEO
 *          defined in "server.h" . Later version may define new streams.
 * @return a new GstRTSPUrl , properly allocated
 */
GstRTSPUrl * url_alloc(GstRTSPUrl**loc,const int flag){
    *loc=(GstRTSPUrl*)malloc(sizeof(GstRTSPUrl));
    switch (flag){
        case INDEX_ADDR_VIDEO:
            gst_rtsp_url_parse(ADDR_VIDEO,loc);
        case INDEX_ADDR_DATA:
            gst_rtsp_url_parse(ADDR_DATA,loc);
            break;
        default:
            return NULL;

    }
    return *loc;

}
/***
 * get_url_instance()
 *      returns initialized and ready addresses , behaves just like siglenton
 * for example
 *          get_url_instance(INDEX_ADDR_VIDEO) -> "rtsp://127.0.0.1:8000/str"
 * @param flag
 *          Parameter flag takes any macro of type INDEX_ADDR_** @see server.h
 * @return a allocated url
 * @note , dont release the returning object , call @see static_url_free() in exit.
 */
GstRTSPUrl * get_url_instance(const int flag){
    static GstRTSPUrl**url=static_urls_alloc();
    g_print("REQUESTED %d\n",flag);
    return !url[flag]?url_alloc(&url[flag],flag):url[flag];
}
int main(int argc,char *argv[]){


    //-------------Version Numbers -------------------------------//
    guint 			major,		//major version number
            minor,		//--//
            nano,
            pico;
    //----------Misc-------------------------------------------------
    guint                   any_event_listener_watch_id;
    GMainLoop               *main_loop;     //main threads loop object
    GstBus 			        *main_bus;	//main bus to submit the any_event_listener
    putenv("GST_DEBUG_DUMP_DOT_DIR=/home/noreasonexception/CLionProjects/");
    putenv("GST_DEBUG=4");
    GstRTSPServer *main_server;
    GstRTSPMountPoints *mount_points;
    GstRTSPMediaFactory*media_factory_video;



    //Initialization
    gst_init	(&argc,&argv);				//initialize gstreamer
    gst_version	(&major,&minor,&nano,&pico);		//get version numbes to print...
    g_print		("[INFO] Gstreamer v%d.%d.%d.%d Ready...\n",major,minor,nano,pico);
    GMainLoop*loop=g_main_loop_new(NULL,FALSE);

    if(!(main_server= gst_rtsp_server_new())){
        g_print("[ERR]main server object failure at initialization");
        return -1;
    }
    g_print("[INFO]Main server initializedOK");
    if(!(mount_points=gst_rtsp_server_get_mount_points(main_server))){
        g_print("[ERR]Mount points getter is failed");
        return -1;
    }
    if(!(media_factory_video=gst_rtsp_media_factory_new())){
        g_print("[ERR]Media factory has encountered an error in initialization");
        return -1;
    }
    gst_rtsp_media_factory_set_launch(media_factory_video,"(wrappercamerabinsrc ! x264enc ! rtph264pay name=pay0  )");
    GstElement *elemstr = gst_rtsp_media_factory_create_element(media_factory_video,get_url_instance(INDEX_ADDR_VIDEO));


    GST_DEBUG_BIN_TO_DOT_FILE(GST_BIN(elemstr), GST_DEBUG_GRAPH_SHOW_ALL, "pipeline");


    GstRTSPMountPoints*mountPoints=gst_rtsp_server_get_mount_points(main_server);
    gst_rtsp_mount_points_add_factory(mount_points,"/str",media_factory_video);
    gst_rtsp_server_set_address(main_server,"127.0.0.1");
    gst_rtsp_server_set_service(main_server,"8000");
    gst_rtsp_server_attach(main_server,NULL);
    g_main_loop_run(loop);

}
