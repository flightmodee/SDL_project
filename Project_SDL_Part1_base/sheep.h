//
// Created by xplo on 27/10/2021.
//
#pragma once
#include "Project_SDL1.h"
#include "animal.h"
#include <ctime>

class sheep : public animal {

public:
  sheep(const std::string& file_path, SDL_Surface* window_surface_ptr, std::set<std::string> properties);
  ~sheep() override;
  void move() override;
  void interact(std::shared_ptr<animal> otherAnimal, ground& ground) override;
  animal* whoIsFemale(const std::shared_ptr<animal> &otherAnimal);
  void copyProperties(std::shared_ptr<animal> a);
  bool canMakeBabies(const std::shared_ptr<animal>& otherAnimal);
};
