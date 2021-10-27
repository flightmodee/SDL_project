//
// Created by xplo on 27/10/2021.
//

#include "headers.h"
#include "animal.h"
#include "sheep.h"

sheep::sheep(const std::string& file_path, SDL_Surface* window_surface_ptr) : 
    animal(file_path, window_surface_ptr, true, true){
    pos_x() = frame_boundary + std::rand() % (frame_width - 2 * frame_boundary);
    pos_y() = frame_boundary + std::rand() % (frame_height - 2 * frame_boundary);
    vel_x() = 40 - std::rand() % 80;
    vel_y() = 40 - std::rand() % 80;
    properties() = { "sheep","alive","male"};
}

void sheep::move(){
    constrained_linear_move_(pos_x(), pos_y(), vel_x(), vel_y());

}

sheep::~sheep() {
  SDL_FreeSurface(image_ptr_);
  std::cout << "Oh me, oh my, a sheep has been destroyed, whatever shall we do?" << std::endl;
}