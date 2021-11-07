//
// Created by xplo on 27/10/2021.
//

#include "wolf.h"
#include "ground.h"
#include "headers.h"


wolf::wolf(const std::string& file_path, SDL_Surface* window_surface_ptr, ground& ground_ptr)
    : timed_animal(file_path, window_surface_ptr, ground_ptr){

    properties_ = {"wolf", "adult"};
}


void wolf::move(){
  constrained_linear_move_(pos_x(), pos_y(), vel_x(), vel_y());
}

void wolf::interact(std::shared_ptr<moving_object> otherAnimal) {

  if (otherAnimal->hasProperty("sheep")) {
    auto& surrounding = ground_ptr_.getAnimals();
    surrounding.erase(std::remove(surrounding.begin(), surrounding.end(), otherAnimal), surrounding.end());
  }

  setTimer();
}

void wolf::evolve() {
  auto& surrounding = ground_ptr_.getAnimals();
  auto new_ground = std::vector<std::shared_ptr<moving_object>>();

  for (auto& p : surrounding){
    if (p.get() == this) {
      surrounding.erase(std::remove(surrounding.begin(), surrounding.end(), p), surrounding.end());
      break;
    }

  }
}

wolf::~wolf() {
  std::cout << "A wolf is gone. Good riddance, it'd prey on our precious sheep." << std::endl;
  SDL_FreeSurface(image_ptr_);
}