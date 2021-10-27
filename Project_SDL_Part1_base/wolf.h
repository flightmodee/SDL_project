//
// Created by xplo on 27/10/2021.
//

#pragma once

#include "Project_SDL1.h"
#include "animal.h"

class wolf : public animal {
public:
  wolf(const std::string& file_path, SDL_Surface* window_surface_ptr);
  ~wolf() override;
  void move() override;
};
