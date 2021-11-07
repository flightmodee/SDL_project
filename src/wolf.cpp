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

void wolf::interact(std::shared_ptr<moving_object> otherObject, double distance) {

  if (otherObject->hasProperty("sheep") && distance < 30.0) {
    auto& surrounding = ground_ptr_.getObjects();
    surrounding.erase(std::remove(surrounding.begin(), surrounding.end(), otherObject), surrounding.end());
    setTimer();
  }
  if (otherObject->hasProperty("shepherd_dog") && distance < 200.0) {
    double vAx = this->vel_x();
    double vAy = this->vel_y();
    double vBx = otherObject->vel_x();
    double vBy = otherObject->vel_y();
    if (vBx < 0 && vAx >0 || vBx > 0 && vAx < 0) {
      this->vel_x() = -vAx;

    }
    if (vBx < 0 && vAx < 0 || vBx > 0 && vAx > 0) {
      this->vel_x() = vAx;
    }
    if (vBy < 0 && vAy >0 || vBy > 0 && vAy < 0) {
      this->vel_y() = -vAy ;
    }
    if (vBy < 0 && vAy < 0 || vBy > 0 && vAy > 0) {
      this->vel_y() = vAy ;
    }
  }
  addProperty("boosted");

}

void wolf::evolve() {
  auto& surrounding = ground_ptr_.getObjects();
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