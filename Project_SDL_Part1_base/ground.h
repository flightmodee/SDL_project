//
// Created by xplo on 27/10/2021.
//
#pragma once

#include "headers.h"
#include "Project_SDL1.h"
#include "declarations.hh"
#include "shepherd.h"

class ground {
private:
	shepherd* player_;
	std::vector<std::shared_ptr<animal>> animals_;
	SDL_Surface* window_surface_ptr_;


public:
  ground() = default; // todo: Ctor
  ground(SDL_Surface* window_surface_ptr);
  ~ground() = default;
  void add_animal(const std::shared_ptr<animal>& a);
  void update();
  [[nodiscard]] std::vector<std::shared_ptr<animal>> getAnimals() const;
  shepherd getPlayer() const;
  void set_ptr(SDL_Surface* window_surface_ptr);
};