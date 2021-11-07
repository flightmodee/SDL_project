//
// Created by xplo on 27/10/2021.
//
#pragma once
#include "Project_SDL1.h"
#include "timed_animal.h"
#include "animal.h"



class wolf : public timed_animal {
public:
  wolf(const std::string& file_path, SDL_Surface* window_surface_ptr, ground& ground_ptr);
  ~wolf() override;
  void move() override;
  void evolve() override;
  void interact(std::shared_ptr<moving_object> otherAnimal) override;
};
