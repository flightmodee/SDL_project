//
// Created by xplo on 27/10/2021.
//

#include "headers.h"
#include "sheep.h"
#include "ground.h"

sheep::sheep(const std::string& file_path, SDL_Surface* window_surface_ptr) :
    
    animal(file_path, window_surface_ptr){
    pos_x() = frame_boundary + std::rand() % (frame_width - 2 * frame_boundary);
    pos_y() = frame_boundary + std::rand() % (frame_height - 2 * frame_boundary);
    vel_x() = 40 - std::rand() % 80;
    vel_y() = 40 - std::rand() % 80;
    properties() = { "sheep","alive",gender_[rand() & 1],"adult","offspring"}; //the sheep can be a male or a female
}
void sheep::move(){
    constrained_linear_move_(pos_x(), pos_y(), vel_x(), vel_y());
}




void sheep::interact(animal* otherAnimal,ground& ground, std::vector<std::shared_ptr<animal>>& new_sheeps) {
    if (otherAnimal->hasprop("wolf")) {
        double vAx = this->vel_x();
        double vAy = this->vel_y();
        double vBx = otherAnimal->vel_x();
        double vBy = otherAnimal->vel_y();
        if (vBx < 0 && vAx >0 || vBx > 0 && vAx < 0) {
            this->vel_x() = -vAx * 1, 5;
        }
        if (vBx < 0 && vAx < 0 || vBx > 0 && vAx > 0) {
            this->vel_x() = vAx * 1, 5;
        }
        if (vBy < 0 && vAy >0 || vBy > 0 && vAy < 0) {
            this->vel_y() = -vAy*1,5;
        }
        if (vBy < 0 && vAy < 0 || vBy > 0 && vAy > 0) {
            this->vel_y() = vAy * 1, 5;
        }
    }
    if (otherAnimal->hasprop("sheep")) {
        if (this->hasprop("female") && otherAnimal->hasprop("male") || this->hasprop("female") && otherAnimal->hasprop("male")) {
            std::cout << "let's make babies :)" << std::endl;

            //TODO: Resolve the problem :D
            auto s = std::make_shared<sheep>("./media/lamb.png", window_surface_ptr_);
            /*new_sheeps.push_back(s); */
            ground.add_animal(s);
            
        }
    }
}

sheep::~sheep() {
  SDL_FreeSurface(image_ptr_);
  std::cout << "Oh me, oh my, a sheep has been destroyed, whatever shall we do?" << std::endl;
}