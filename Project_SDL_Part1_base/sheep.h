//
// Created by xplo on 27/10/2021.
//
#pragma once
#include "Project_SDL1.h"
#include "animal.h"

class sheep : public animal {
private:
  Uint32 sexTimer_;
public:
  sheep(const std::string& file_path, SDL_Surface* window_surface_ptr);
  ~sheep() override;
  void move() override;
  // implement functions that are purely virtual in base class
  //void interact(animal* otherAnimal, std::vector<std::shared_ptr<animal>>& new_sheeps ) override;
  void interact(std::shared_ptr<animal> otherAnimal, ground& ground) override;
};
