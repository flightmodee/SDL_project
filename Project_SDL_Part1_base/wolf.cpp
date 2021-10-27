//
// Created by xplo on 27/10/2021.
//

#include "headers.h"
#include "wolf.h"

wolf::wolf(const std::string& file_path, SDL_Surface* window_surface_ptr) : animal(file_path, window_surface_ptr, false, false){}


void wolf::move(){

  int surface_width = image_ptr_->clip_rect.w;
  int surface_height = image_ptr_->clip_rect.h;

  if (y_ >= frame_height - frame_boundary - surface_height)
    vertical_direction_ = false;

  if (y_ <= frame_boundary)
    vertical_direction_ = true;

  if (x_ >= frame_width - frame_boundary - surface_width)
    horizontal_direction_ = false;

  if (x_ <= frame_boundary)
    horizontal_direction_ = true;

  if (vertical_direction_)
    y_+=1;
  else
    y_-=1;

  if (horizontal_direction_)
    x_+=1;
  else
    x_-=1;

}

wolf::~wolf() {
  std::cout << "A wolf is gone. Good riddance, it'd prey on our precious sheep." << std::endl;
  SDL_FreeSurface(image_ptr_);
}