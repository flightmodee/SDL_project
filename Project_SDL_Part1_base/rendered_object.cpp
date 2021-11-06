//
// Created by xplo on 06/11/2021.
//

#include "headers.h"
#include "rendered_object.h"


rendered_object::rendered_object(SDL_Surface *window_surface_ptr, SDL_Surface *image_ptr, const std::set<std::string>& properties)
    : interacting_object{properties}, window_surface_ptr_{window_surface_ptr}, image_ptr_{image_ptr} {
  pos_x_ = frame_boundary + std::rand() % (frame_width - 2 * frame_boundary);
  pos_y_ = frame_boundary + std::rand() % (frame_height - 2 * frame_boundary);

}

void rendered_object::setSurface(const std::string& path, SDL_Surface *newSurface) {
  window_surface_ptr_ = load_surface_for(path, newSurface);
}

unsigned int rendered_object::pos_x() const { return pos_x_; }
unsigned int& rendered_object::pos_x() { return pos_x_; }
unsigned int rendered_object::pos_y() const { return pos_y_; }
unsigned int& rendered_object::pos_y() { return pos_y_; }

