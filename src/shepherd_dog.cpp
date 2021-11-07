//
// Created by xplo on 27/10/2021.
//

#include "headers.h"
#include "shepherd_dog.h"
#include "ground.h"
#include "shepherd.h"

shepherd_dog::shepherd_dog(const std::string& file_path, SDL_Surface* window_surface_ptr, ground& ground_ptr, std::shared_ptr<shepherd> player) :
    player_{player},
    animal(file_path, window_surface_ptr, ground_ptr){
    pos_x_ = frame_boundary + std::rand() % (frame_width - 2 * frame_boundary);
    pos_y_ = frame_boundary + std::rand() % (frame_height - 2 * frame_boundary);
    vel_x_ = 40 - std::rand() % 80;
    vel_y_ = 40 - std::rand() % 80;
    addProperty("shepherd_dog");
}
void shepherd_dog::move(){
    
    double x = player_->pos_x();
    double y = player_->pos_y();
    pos_x_ = 100.0 * cos(t / 180) + x;
    pos_y_ = 100.0 * sin(t / 180) + y;
    t = t + 1.0;
}




void shepherd_dog::interact(std::shared_ptr<moving_object> otherObject, double distance){
}
   


shepherd_dog::~shepherd_dog() {
  SDL_FreeSurface(image_ptr_);
  std::cout << "Oh me, oh my, a shepherd_dog has been destroyed, whatever shall we do?" << std::endl;
}