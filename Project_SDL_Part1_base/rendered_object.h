//
// Created by xplo on 06/11/2021.
//

#pragma once
#include "headers.h"
#include "interacting_object.h"

class rendered_object : public interacting_object {
protected:
  SDL_Surface* window_surface_ptr_;
  SDL_Surface* image_ptr_;
  unsigned int pos_x_;
  unsigned int pos_y_;



public:
  rendered_object(SDL_Surface* window_surface_ptr, SDL_Surface* image_ptr, const std::set<std::string>& properties);
  ~rendered_object() = default;
  void setSurface(const std::string& path, SDL_Surface *newSurface);

  unsigned int pos_x() const;
  unsigned int& pos_x();
  unsigned int pos_y() const;
  unsigned int& pos_y();

};