//
// Created by xplo on 06/11/2021.
//

#include "headers.h"
#include "rendered_object.h"


rendered_object::rendered_object(SDL_Surface *window_surface_ptr, SDL_Surface *image_ptr, const std::set<std::string>& properties)
    : interacting_object{properties}, window_surface_ptr_{window_surface_ptr}, image_ptr_{image_ptr} {
  pos_x_ = frame_boundary + std::rand() % (frame_width - 2 * frame_boundary);
  pos_y_ = frame_boundary + std::rand() % (frame_height - 2 * frame_boundary);

}

void rendered_object::setSurface(const std::string& path, SDL_Surface *newSurface) {
  window_surface_ptr_ = load_surface_for(path, newSurface);
}


void rendered_object::draw() const{

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


double rendered_object::pos_x() const { return pos_x_; }
double& rendered_object::pos_x() { return pos_x_; }
double rendered_object::pos_y() const { return pos_y_; }
double& rendered_object::pos_y() { return pos_y_; }
double rendered_object::get_w() {return image_ptr_->w;}
double rendered_object::get_h() {return image_ptr_->h;}
