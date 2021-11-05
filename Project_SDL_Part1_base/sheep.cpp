//
// Created by xplo on 27/10/2021.
//

#include "headers.h"
#include "sheep.h"
#include "ground.h"

constexpr unsigned int sexFreeDuration = 10;

//We'll only set the timer if the newly-created sheep is a female.
//Male sheep do not need, at first, to have their timer set.
sheep::sheep(const std::string& file_path, SDL_Surface* window_surface_ptr, std::set<std::string> properties)
    : animal(file_path, window_surface_ptr) {

    properties_ = std::move(properties);
    std::string gender[2] = {"male", "female"};
    pos_x_ = frame_boundary + std::rand() % (frame_width - 2 * frame_boundary);
    pos_y_ = frame_boundary + std::rand() % (frame_height - 2 * frame_boundary);
    vel_x_ = 40 - std::rand() % 80;
    vel_y_ = 40 - std::rand() % 80;
    properties_.insert(gender[rand() & 1]); //the sheep can be a male or a female

    //We'll only set a timer for the female sheep, on their creation
    //We'll also add a special property which will be used in the context of
    //sheep x sheep interaction
    if (properties_.count("female") && !properties_.count("lamb")) {
      timer_ = std::chrono::system_clock::now();
      properties_.insert("just_spawned");
    }
}
void sheep::move(){
    constrained_linear_move_(pos_x(), pos_y(), vel_x(), vel_y());
}


animal* sheep::whoIsFemale(const std::shared_ptr<animal>& otherAnimal){
  if (otherAnimal->hasProp("female"))
    return (otherAnimal.get());

  else if (hasProp("female"))
    return (this);
  else
    throw std::runtime_error("This shouldn't have happened at all.\n");
}

void sheep::copyProperties(std::shared_ptr<animal> a){
  a->pos_x() = pos_x_ + 50;
  a->pos_y() = pos_y_ + 50;
  a->vel_x() = vel_x_;
  a->vel_y() = vel_y_;
}

bool sheep::canMakeBabies(const std::shared_ptr<animal>& otherAnimal){
  if (this->hasProp("female") && otherAnimal->hasProp("male") || this->hasProp("female") && otherAnimal->hasProp("male"))
    if (!this->hasProp("lamb") && !otherAnimal->hasProp("lamb"))
      return (true);

  return (false);
}

void sheep::interact(std::shared_ptr<animal> otherAnimal, ground& ground) {
    /*if (otherAnimal->hasprop("wolf")) {
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
    if (otherAnimal->hasProp("sheep")) {
        if (this->canMakeBabies(otherAnimal)){

          auto female = this->whoIsFemale(otherAnimal);
          auto now = std::chrono::system_clock::now();
          auto delay = std::chrono::duration_cast<std::chrono::seconds>(now - female->getTimer()).count();

          if (delay > sexFreeDuration || female->properties().count("just_spawned")){
            std::cout << "let's make babies :)" << std::endl;


            auto set = std::set<std::string>{"sheep", "lamb"};
            auto s = std::make_shared<sheep>("/home/xplo/ESIEE/cpp/Project_SDL_Part1_ABDOUCHE/media/lamb.png", window_surface_ptr_, set);
            copyProperties(s);
            ground.getAnimals().push_back(s);
            female->getTimer() = std::chrono::system_clock::now();
            if (female->properties().count("just_spawned"))
              female->properties().erase("just_spawned");
          }
        }
    }
}

sheep::~sheep() {
  SDL_FreeSurface(image_ptr_);
  std::cout << "Oh me, oh my, a sheep has been destroyed, whatever shall we do?" << std::endl;
}

