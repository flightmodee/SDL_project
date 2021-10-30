//
// Created by xplo on 27/10/2021.
//

#include "headers.h"
#include "wolf.h"

wolf::wolf(const std::string& file_path, SDL_Surface* window_surface_ptr) : animal(file_path, window_surface_ptr){
    pos_x() = frame_boundary + std::rand() % (frame_width - 2 * frame_boundary);
    pos_y() = frame_boundary + std::rand() % (frame_height - 2 * frame_boundary);
    vel_x() = 40 - std::rand() % 80;
    vel_y() = 40 - std::rand() % 80;
    properties() = { "wolf","alive" };
}


void wolf::move(){

    constrained_linear_move_(pos_x(), pos_y(), vel_x(), vel_y());

}

void wolf::interact(animal* otherAnimal/*,ground& ground*/) {
}

wolf::~wolf() {
  std::cout << "A wolf is gone. Good riddance, it'd prey on our precious sheep." << std::endl;
  SDL_FreeSurface(image_ptr_);
}