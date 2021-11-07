//
// Created by xplo on 07/11/2021.
//

#pragma once
#include "rendered_object.h"

class moving_object : public rendered_object {
protected:
  double vel_x_;
  double vel_y_;
public:
  moving_object(SDL_Surface *window_surface_ptr, SDL_Surface *image_ptr, const std::set<std::string>& properties);
  ~moving_object() = default;

  void copyProperties(moving_object* mom);

  virtual void move() = 0;
  double vel_x() const;
  double& vel_x();
  double vel_y() const;
  double& vel_y();

};