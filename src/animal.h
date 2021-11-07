//
// Created by xplo on 27/10/2021.
//
#pragma once
#include "moving_object.h"


class animal: public moving_object {
protected:
  ground& ground_ptr_;

public:
  animal(const std::string& file_path, SDL_Surface* window_surface_ptr, ground& ground_ptr);
  virtual ~animal() = default;


};
