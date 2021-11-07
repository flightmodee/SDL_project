//
// Created by xplo on 07/11/2021.
//

#include "moving_object.h"
#include "headers.h"

moving_object::moving_object(SDL_Surface *window_surface_ptr, SDL_Surface *image_ptr, const std::set<std::string>& properties)
    : rendered_object(window_surface_ptr, image_ptr, properties), vel_x_{20.0+rand()%20}, vel_y_{20.0+rand()%20} {}


void moving_object::copyProperties(moving_object* mom){
  pos_x_ = mom->pos_x_ + distanceFromMommy;
  pos_y_ = mom->pos_y_ + distanceFromMommy;
  vel_x_ = mom->vel_x_;
  vel_y_ = mom->vel_y_;

}


double moving_object::vel_x() const { return vel_x_; }
double& moving_object::vel_x() { return vel_x_; }
double moving_object::vel_y() const { return vel_y_; }
double& moving_object::vel_y() { return vel_y_; }

