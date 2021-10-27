//
// Created by xplo on 27/10/2021.
//

#include "headers.h"
#include "animal.h"
#include "sheep.h"

sheep::sheep(const std::string& file_path, SDL_Surface* window_surface_ptr) : 
    animal(file_path, window_surface_ptr, true, true){
    properties() = { "sheep","alive","male"};
}

void sheep::move(){

  int surface_width = image_ptr_->clip_rect.w;
  int surface_height = image_ptr_->clip_rect.h;

  if (pos_y_ >= frame_height - frame_boundary - surface_height)
    vertical_direction_ = false;

  if (pos_y_ <= frame_boundary)
    vertical_direction_ = true;

  if (pos_x_ >= frame_width - frame_boundary - surface_width)
    horizontal_direction_ = false;

  if (pos_x_ <= frame_boundary)
    horizontal_direction_ = true;

  if (vertical_direction_)
    pos_y_+=1;
  if (!vertical_direction_)
    pos_y_-=1;

  if (horizontal_direction_)
    pos_x_+=1;

  if (!horizontal_direction_)
    pos_x_-=1;

}

sheep::~sheep() {
  SDL_FreeSurface(image_ptr_);
  std::cout << "Oh me, oh my, a sheep has been destroyed, whatever shall we do?" << std::endl;
}