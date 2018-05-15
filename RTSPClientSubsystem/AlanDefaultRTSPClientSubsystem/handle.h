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

#define OFFSET_TO_ID    (*(map.data+10)+(indx+=1))

#endif //IKARUS_PROJECT_HANDLE_H
