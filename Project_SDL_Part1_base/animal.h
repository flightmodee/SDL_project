//
// Created by xplo on 27/10/2021.
//

#include "headers.h"

#pragma once

class animal {
protected:
  SDL_Surface* window_surface_ptr_; // ptr to the surface on which we want the
                                    // animal to be drawn, also non-owning
  SDL_Surface* image_ptr_; // The texture of the sheep (the loaded image), use
                                    // load_surface_for
  double pos_x_;
  double pos_y_;
  double vel_x_;
  double vel_y_;
  bool horizontal_direction_; //These booleans are used to represent the horizontal and vertical directions of an animal's movement.
                              // If they're true, they respectively indicate the animal is moving downwards and rightwards, and vice versa.
  bool vertical_direction_;
  std::set<std::string> properties_; //This set are used to know more about the type, the status (alive or dead) of the animal
 

public:
  animal(const std::string& file_path, SDL_Surface* window_surface_ptr, bool horizontal_direction, bool vertical_direction);
  virtual ~animal() = default;

  void draw() const;

  virtual void move() = 0;
  double pos_x() const { return pos_x_; };
  double& pos_x() { return pos_x_; };
  double pos_y() const { return pos_y_; };
  double& pos_y() { return pos_y_; };
  double vel_x() const { return vel_x_; };
  double& vel_x() { return vel_x_; };
  double vel_y() const { return vel_y_; };
  double& vel_y() { return vel_y_; };

  std::set<std::string> properties() const { return properties_; };
  std::set<std::string>& properties() { return properties_; };

};
