//
// Created by xplo on 27/10/2021.
//

#include "wolf.h"
#include "ground.h"
#include "headers.h"


wolf::wolf(const std::string& file_path, SDL_Surface* window_surface_ptr) : animal(file_path, window_surface_ptr){

    properties_ = {"wolf", "adult"};
    pos_x_ = frame_boundary + std::rand() % (frame_width - 2 * frame_boundary);
    pos_y_ = frame_boundary + std::rand() % (frame_height - 2 * frame_boundary);
    vel_x_ = 40 - std::rand() % 80;
    vel_y_ = 40 - std::rand() % 80;
}


void wolf::move(){
  constrained_linear_move_(pos_x(), pos_y(), vel_x(), vel_y());
}

void wolf::interact(std::shared_ptr<animal> otherAnimal, ground& ground) {

  if (otherAnimal->hasProp("sheep")) {
    std::vector<std::shared_ptr<animal>> &v = ground.getAnimals();
    v.erase(std::remove(v.begin(), v.end(), otherAnimal), v.end());
  }

}
wolf::~wolf() {
  std::cout << "A wolf is gone. Good riddance, it'd prey on our precious sheep." << std::endl;
  SDL_FreeSurface(image_ptr_);
}