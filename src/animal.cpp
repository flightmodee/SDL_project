//
// Created by xplo on 27/10/2021.
//

#include "headers.h"
#include "animal.h"
#include "ground.h"


animal::animal(const std::string &file_path, SDL_Surface *window_surface_ptr, ground& ground_ptr)
    : moving_object(window_surface_ptr, load_surface_for(file_path, window_surface_ptr), {"adult"}), ground_ptr_{ground_ptr} {}


