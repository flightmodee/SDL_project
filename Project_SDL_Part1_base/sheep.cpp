//
// Created by xplo on 27/10/2021.
//

#include "headers.h"
#include "sheep.h"
#include "ground.h"

//We'll only set the timer if the newly-created sheep is a female.
//Male sheep do not need, at first, to have their timer set.
sheep::sheep(const std::string& file_path, SDL_Surface* window_surface_ptr, std::set<std::string> properties, ground& ground_ptr)
    : timed_animal(file_path, window_surface_ptr, ground_ptr){

    properties_ = std::move(properties);
    std::string gender[2] = {"male", "female"};
    properties_.insert(gender[rand() & 1]); //the sheep can be a male or a female

    //We'll only set a timer for the female sheep, on their creation
    //We'll also add a special property which will be used in the context of
    //sheep x sheep interaction
    if (properties_.count("female") && !properties_.count("lamb"))
      properties_.insert("just_spawned");

}
void sheep::move() {
  constrained_linear_move_(pos_x(), pos_y(), vel_x(), vel_y());
}

void sheep::interact(std::shared_ptr<moving_object> otherAnimal) {
    /*if (otherAnimal->hasProperty("wolf")) {
        double vAx = this->vel_x();
        double vAy = this->vel_y();
        double vBx = otherAnimal->vel_x();
        double vBy = otherAnimal->vel_y();
        if (vBx < 0 && vAx >0 || vBx > 0 && vAx < 0) {
            this->vel_x() = -vAx * 1.5;

        }
        if (vBx < 0 && vAx < 0 || vBx > 0 && vAx > 0) {
            this->vel_x() = vAx * 1.5;
        }
        if (vBy < 0 && vAy >0 || vBy > 0 && vAy < 0) {
            this->vel_y() = -vAy * 1.5;
        }
        if (vBy < 0 && vAy < 0 || vBy > 0 && vAy > 0) {
            this->vel_y() = vAy * 1.5;
        }
    }*/
      if (otherAnimal->hasProperty("sheep") && !otherAnimal->hasProperty("lamb") && otherAnimal->hasProperty("male")){
        if (this->hasProperty("female") && !this->hasProperty("lamb")) {

          auto now = std::chrono::system_clock::now();
          auto delay = std::chrono::duration_cast<std::chrono::seconds>(now - this->timer_).count();


          if (delay > sexFreeDuration || getProperties().count("just_spawned")){//sexy time
            //resetting the female's timer
            setTimer();
            if (getProperties().count("just_spawned"))
              getProperties().erase("just_spawned");

            //Creating a lamb
            auto set = std::set<std::string>{"sheep", "lamb"};
            auto lamb = std::make_shared<sheep>(samy_lamb_path.data(), window_surface_ptr_, set, ground_ptr_);

            //the lamb will follow his mother, at first
            lamb->copyProperties(this);
            //adding lamb to ground
            ground_ptr_.add_timed_animal(lamb); //we'll keep track of its evolution
            ground_ptr_.add_animal(lamb);

          }
        }
      }

}

void sheep::evolve() {

  if (hasProperty("lamb")){
    image_ptr_ = load_surface_for(samy_sheep_path.data(), window_surface_ptr_);
    //the lamb now part ways with its mother, how sad
  }
}

sheep::~sheep() {
  SDL_FreeSurface(image_ptr_);
  std::cout << "Oh me, oh my, a sheep has been destroyed, whatever shall we do?" << std::endl;
}



