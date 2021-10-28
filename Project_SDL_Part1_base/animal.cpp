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
  SDL_Rect pos;
  pos.x = (int)pos_x();
  pos.y = (int)pos_y();
  std::cout << pos.w << " " << pos.h << std::endl;
  SDL_BlitScaled(image_ptr_, NULL, window_surface_ptr_, &pos);
}

bool animal::isSheep() {
    return properties().count("sheep");
}
bool animal::isWolf() {
    return properties().count("wolf");

}