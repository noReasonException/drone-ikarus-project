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
#include <stdarg.h>
#include <gst/gst.h>
#include "common.h"

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
extern  gboolean generic_initializer(const int flags, int num, ...){

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
            g_print("[INIT][INFO] %s factory loaded\n",name);
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
            g_print("[LOAD][INFO] %s element loaded\n",name);
        }
    }
    if(flags&GIN_FREE_STRING_AFTER) g_free(name);
    if(stop)return FALSE;
    return TRUE;
}
