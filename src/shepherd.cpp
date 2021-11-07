//
// Created by xplo on 27/10/2021.
//

#include "headers.h"
#include "shepherd.h"
#include "ground.h"

shepherd::shepherd(const std::string& file_path, SDL_Surface* window_surface_ptr) : playable_character(file_path, window_surface_ptr) {

    pos_x_ = frame_boundary + std::rand() % (frame_width - 2 * frame_boundary);
    pos_y_ = frame_boundary + std::rand() % (frame_height - 2 * frame_boundary);
    vel_x_ = 40;
    vel_y_ = 40;
}
void shepherd::move() {
    while (SDL_PollEvent(&event_)) {
            if (event_.key.keysym.sym == SDLK_LEFT || event_.key.keysym.sym == SDLK_q)
               pos_x() -= vel_x(); 
            if (event_.key.keysym.sym == SDLK_RIGHT || event_.key.keysym.sym == SDLK_d)
                pos_x() += vel_x();
            if (event_.key.keysym.sym == SDLK_UP || event_.key.keysym.sym == SDLK_z)
                pos_y() -= vel_y();
            if (event_.key.keysym.sym == SDLK_DOWN || event_.key.keysym.sym == SDLK_s)
                pos_y() += vel_y();
        
    }
}

void shepherd::interact(std::shared_ptr<moving_object> otherObject, double distance) {

}


shepherd::~shepherd() {
    SDL_FreeSurface(image_ptr_);
    std::cout << "Oh me, oh my, a shepherd has been destroyed, whatever shall we do?" << std::endl;
}
