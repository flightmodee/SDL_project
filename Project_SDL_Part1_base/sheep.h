//
// Created by xplo on 27/10/2021.
//

#include "Project_SDL1.h"


#pragma once

class sheep : public animal {
	std::string gender_[2] = { "male","female" };
public:
  sheep(const std::string& file_path, SDL_Surface* window_surface_ptr);
  ~sheep() override;
  void move() override;
  // implement functions that are purely virtual in base class
  void interact(animal* otherAnimal) override;
};