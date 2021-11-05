//
// Created by xplo on 27/10/2021.
//

#include "headers.h"
#include "animal.h"
#include "ground.h"

constexpr unsigned int distanceFromMommy = 50;

animal::animal(const std::string &file_path, SDL_Surface *window_surface_ptr):
    window_surface_ptr_{window_surface_ptr}, image_ptr_{ load_surface_for(file_path, window_surface_ptr) },
    h_{image_ptr_->h}, w_{image_ptr_->w}{}

void animal::draw() const{

  if (window_surface_ptr_ == nullptr || image_ptr_ == nullptr){
    std::cout << "pointers aren't ok, bro, do something";
    return;
  }

  //These two next lines are used to get rid of the PNG backgrounds
  Uint32 color_key = SDL_MapRGB(image_ptr_->format, 0, 0, 0);
  SDL_SetColorKey(image_ptr_, SDL_TRUE, color_key);
  SDL_Rect pos;
  pos.x = (int)pos_x();
  pos.y = (int)pos_y();
  pos.h = geth();
  pos.w = getw();
  SDL_BlitScaled(image_ptr_, nullptr, window_surface_ptr_, &pos);
}


bool animal::hasProp(std::string a) {
    return properties().count(a);
}

void animal::copyMommyProperties(animal* mom){
  pos_x_ = mom->pos_x_ + distanceFromMommy;
  pos_y_ = mom->pos_y_ + distanceFromMommy;
  vel_x_ = mom->vel_x_;
  vel_y_ = mom->vel_y_;
}



std::chrono::time_point<std::chrono::system_clock>& animal::getTimer(){
    return timer_;
};

