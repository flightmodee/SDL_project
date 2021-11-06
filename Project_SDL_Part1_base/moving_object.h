//
// Created by xplo on 07/11/2021.
//

#pragma once
#include "headers.h"
#include "rendered_object.h"

class moving_object : public rendered_object{
protected:
  int vel_x_;
  int vel_y_;
public:
  moving_object(SDL_Surface *window_surface_ptr, SDL_Surface *image_ptr, const std::set<std::string>& properties);
  ~moving_object() = default;

  virtual void move() = 0;
  int vel_x() const;
  int& vel_x();
  int vel_y() const;
  int& vel_y();

};