//
// Created by xplo on 27/10/2021.
//

#include "headers.h"
#include "sheep.h"
#include "ground.h"

sheep::sheep(const std::string& file_path, SDL_Surface* window_surface_ptr) : animal(file_path, window_surface_ptr){

    std::string gender[2] = { "male","female" };
    pos_x_ = frame_boundary + std::rand() % (frame_width - 2 * frame_boundary);
    pos_y_ = frame_boundary + std::rand() % (frame_height - 2 * frame_boundary);
    vel_x_ = 40 - std::rand() % 80;
    vel_y_ = 40 - std::rand() % 80;
    properties_ = { "sheep",gender[rand() & 1],"adult"}; //the sheep can be a male or a female
    sexTimer_ = 0;

}
void sheep::move(){
    constrained_linear_move_(pos_x(), pos_y(), vel_x(), vel_y());
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
    /*if (otherAnimal->hasprop("sheep")) {
        if (this->hasprop("female") && otherAnimal->hasprop("male") || this->hasprop("female") && otherAnimal->hasprop("male")) {
            std::cout << "let's make babies :)" << std::endl;

            //TODO: create a sheep
            auto s = std::make_shared<sheep>("/home/xplo/ESIEE/cpp/Project_SDL_Part1_ABDOUCHE/media/sheep.png", window_surface_ptr_);
            ground.getAnimals().push_back(s);
            //auto s = std::make_shared<sheep>("./media/sheep.png", window_surface_ptr_);

        }
    }*/



}

sheep::~sheep() {
  SDL_FreeSurface(image_ptr_);
  std::cout << "Oh me, oh my, a sheep has been destroyed, whatever shall we do?" << std::endl;
}