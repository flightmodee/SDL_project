//
// Created by xplo on 27/10/2021.
//
#pragma once
#include "headers.h"
#include "moving_object.h"
#include "declarations.hh"



class animal: public moving_object {
protected:
  //some animal behaviors are defined by time constraints. Therefore,
  //we'll use some sort of timer to implement said constraints.
  std::chrono::time_point<std::chrono::system_clock> timer_;

public:
  animal(const std::string& file_path, SDL_Surface* window_surface_ptr);
  virtual ~animal() = default;

  void draw() const;

  virtual void move() = 0;

  [[nodiscard]] std::chrono::time_point<std::chrono::system_clock>& getTimer();

  void copyMommyProperties(animal* mom);

};
