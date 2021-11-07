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
  sheep(const sheep& s);
  ~sheep() override;
  void interact(std::shared_ptr<interacting_object> otherObject) override;

};
