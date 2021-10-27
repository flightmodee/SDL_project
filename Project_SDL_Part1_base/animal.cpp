//
// Created by xplo on 27/10/2021.
//

#include "headers.h"
#include "animal.h"

animal::animal(const std::string &file_path, SDL_Surface *window_surface_ptr, bool horizontal_direction, bool vertical_direction)
    : window_surface_ptr_{window_surface_ptr}, horizontal_direction_{horizontal_direction}, vertical_direction_{vertical_direction}{

  image_ptr_ = load_surface_for(file_path, window_surface_ptr);

  //Let's make sure our animals spawn within the boundaries of our zoo.
  pos_x_ = rand() % (frame_width - frame_boundary - image_ptr_->w) + frame_boundary;
  pos_y_ = rand() % (frame_height - frame_boundary - image_ptr_->h) + frame_boundary;

}

void animal::draw() const{

  if (window_surface_ptr_ == nullptr || image_ptr_ == nullptr){
    std::cout << "pointers aren't ok, bro, do something";
    return;
  }

  //These two next lines are used to get rid of the PNG backgrounds
  Uint32 color_key = SDL_MapRGB(image_ptr_->format, 0, 0, 0);
  SDL_SetColorKey(image_ptr_, SDL_TRUE, color_key);
  SDL_Rect sheep_rect;
  sheep_rect.x = pos_x();
  sheep_rect.y = pos_y();

  SDL_BlitSurface(image_ptr_, nullptr, window_surface_ptr_, &sheep_rect);
}