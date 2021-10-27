//
// Created by xplo on 27/10/2021.
//

#include "Project_SDL1.h"


#pragma once

class animal {
protected:
  SDL_Surface* window_surface_ptr_; // ptr to the surface on which we want the
                                    // animal to be drawn, also non-owning
  SDL_Surface* image_ptr_; // The texture of the sheep (the loaded image), use
                                    // load_surface_for
  unsigned int x_;
  unsigned int y_;
  bool horizontal_direction_; //These booleans are used to represent the horizontal and vertical directions of an animal's movement.
                              // If they're true, they respectively indicate the animal is moving downwards and rightwards, and vice versa.
  bool vertical_direction_;

public:
  animal(const std::string& file_path, SDL_Surface* window_surface_ptr, bool horizontal_direction, bool vertical_direction);
  virtual ~animal() = default;

  void draw() const;

  virtual void move() = 0;

};
