//
// Created by xplo on 27/10/2021.
//
#pragma once
#include "Project_SDL1.h"
#include "ground.h"
#include "moving_object.h"
#include "timed_animal.h"
#include <ctime>

class sheep : public timed_animal {

public:
  sheep(const std::string& file_path, SDL_Surface* window_surface_ptr, std::set<std::string> properties, ground& ground_ptr);
  ~sheep() override;
  void interact(std::shared_ptr<moving_object> otherObject) override;

  void move() override;

  void evolve();
};
