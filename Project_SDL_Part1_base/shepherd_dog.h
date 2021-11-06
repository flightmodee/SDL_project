//
// Created by xplo on 27/10/2021.
//
#pragma once
#include "Project_SDL1.h"
#include "animal.h"
#include "shepherd.h"

class shepherd_dog : public animal {
private:
	shepherd* player_;
	double t = 0.0;
public:
  shepherd_dog(const std::string& file_path, SDL_Surface* window_surface_ptr, shepherd* player);
  ~shepherd_dog() override;
  void move() override;
  // implement functions that are purely virtual in base class
  void interact(animal* otherAnimal, ground& ground, std::vector<std::shared_ptr<animal>>& new_sheeps );
};