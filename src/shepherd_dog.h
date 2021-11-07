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
  shepherd_dog(const std::string& file_path, SDL_Surface* window_surface_ptr, ground& ground_ptr,shepherd* player);
  ~shepherd_dog() override;
  void move() override;
  // implement functions that are purely virtual in base class
  void interact(std::shared_ptr<moving_object> otherObject) override;
};