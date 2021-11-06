//
// Created by xplo on 27/10/2021.
//

#include "headers.h"
#include "animal.h"
#include "ground.h"

constexpr unsigned int distanceFromMommy = 50;

animal::animal(const std::string &file_path, SDL_Surface *window_surface_ptr)
    : moving_object(window_surface_ptr, load_surface_for(file_path, window_surface_ptr), {"adult"}) {}

void animal::draw() const{

  if (window_surface_ptr_ == nullptr || image_ptr_ == nullptr){
    std::cout << "pointers aren't ok, bro, do something";
    return;
  }

  //These two next lines are used to get rid of the PNG backgrounds
  Uint32 color_key = SDL_MapRGB(image_ptr_->format, 0, 0, 0);
  SDL_SetColorKey(image_ptr_, SDL_TRUE, color_key);
  SDL_Rect pos;
  pos.x = (int)pos_x_;
  pos.y = (int)pos_y_;
  pos.h = image_ptr_->h;
  pos.w = image_ptr_->w;
  SDL_BlitScaled(image_ptr_, nullptr, window_surface_ptr_, &pos);
}


void animal::copyMommyProperties(animal* mom){
  pos_x_ = mom->pos_x_ + distanceFromMommy;
  pos_y_ = mom->pos_y_ + distanceFromMommy;
  vel_x_ = mom->vel_x_;
  vel_y_ = mom->vel_y_;

  int mom_w = ceil((mom->image_ptr_->w)/1.5);
  int mom_h = ceil((mom->image_ptr_->h)/1.5);

  setDimensions(mom_w, mom_h);
}



std::chrono::time_point<std::chrono::system_clock>& animal::getTimer(){
    return timer_;
}

