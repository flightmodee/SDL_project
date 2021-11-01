//
// Created by xplo on 27/10/2021.
//
#pragma once
#include "Project_SDL1.h"
#include "animal.h"

class sheep : public animal {
	std::string gender_[2] = { "male","female" };
public:
  sheep(const std::string& file_path, SDL_Surface* window_surface_ptr);
  ~sheep() override;
  void move() override;
  // implement functions that are purely virtual in base class
  void interact(animal* otherAnimal, ground& ground, std::vector<std::shared_ptr<animal>>& new_sheeps );
};