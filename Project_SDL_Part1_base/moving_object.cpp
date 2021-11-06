//
// Created by xplo on 07/11/2021.
//

#include "moving_object.h"

moving_object::moving_object(SDL_Surface *window_surface_ptr, SDL_Surface *image_ptr, const std::set<std::string> &properties)
    : rendered_object(window_surface_ptr, image_ptr, properties), vel_x_{40+rand()%80}, vel_y_{40+rand()%80} {}


int moving_object::vel_x() const { return vel_x_; }
int& moving_object::vel_x() { return vel_x_; }
int moving_object::vel_y() const { return vel_y_; }
int& moving_object::vel_y() { return vel_y_; }

