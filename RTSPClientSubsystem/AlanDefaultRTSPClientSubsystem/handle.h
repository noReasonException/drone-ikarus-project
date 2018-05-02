//
// Created by noreasonexception on 5/1/18.
//

#ifndef IKARUS_PROJECT_HANDLE_H
#define IKARUS_PROJECT_HANDLE_H
/****
 * How the ID is taken!?
 * ========================HOW THIS WORKS?!?========================
 * In order to reduce the stream bandwidth (and latency for extracting the actual metadata) a clever
 * approach is used . we have placed the Probe Listeners in just the right place , so in both
 * the server and the client to have in every call the EXACTLY the same data on their buffers
 * so , instead of injecting the ID and extract from the other side , we take raw numbers from known locations
 * as ID . so we have a cpu-load-free way of getting a random number .Nice uh?  :P
 */
#define OFFSET_TO_ID    *(map.data+48)+\
                        *(map.data+49)+\
                        *(map.data+50)+\
                        *(map.data+51)+\
                        *(map.data+52)+\
                        *(map.data+53)
#endif //IKARUS_PROJECT_HANDLE_H
