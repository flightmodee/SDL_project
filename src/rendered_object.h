//
// Created by xplo on 06/11/2021.
//

#pragma once
#include "interacting_object.h"

class rendered_object : public interacting_object {
protected:
  SDL_Surface* window_surface_ptr_;
  SDL_Surface* image_ptr_;
  double pos_x_;
  double pos_y_;



public:
  rendered_object(SDL_Surface* window_surface_ptr, SDL_Surface* image_ptr, const std::set<std::string>& properties);
  ~rendered_object() = default;
  void setSurface(const std::string& path, SDL_Surface *newSurface);
  void draw() const;

  double pos_x() const;
  double& pos_x();
  double pos_y() const;
  double& pos_y();
  double get_w();
  double get_h();

};