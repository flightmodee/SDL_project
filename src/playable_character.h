//
// Created by xplo on 27/10/2021.
//
#pragma once
#include "moving_object.h"


class playable_character: public moving_object {

public:
  playable_character(const std::string& file_path, SDL_Surface* window_surface_ptr);
  virtual ~playable_character() = default;


};