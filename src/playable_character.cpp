// Created by xplo on 27/10/2021.
//

#include "headers.h"
#include "playable_character.h"


    playable_character::playable_character(const std::string &file_path, SDL_Surface *window_surface_ptr)
    : moving_object(window_surface_ptr, load_surface_for(file_path, window_surface_ptr), {"adult"}){};