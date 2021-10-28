//
// Created by xplo on 27/10/2021.
//

#include "headers.h"
#include "animal.h"

animal::animal(const std::string &file_path, SDL_Surface *window_surface_ptr): 
    window_surface_ptr_{window_surface_ptr},
    image_ptr_{ load_surface_for(file_path, window_surface_ptr) }
    {
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