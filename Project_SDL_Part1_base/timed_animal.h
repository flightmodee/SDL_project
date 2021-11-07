//
// Created by xplo on 07/11/2021.
//

#pragma once
#include "animal.h"
#include <chrono>

class timed_animal : public animal {
protected:
  std::chrono::time_point<std::chrono::system_clock> timer_;

public:
  timed_animal(const std::string& file_path, SDL_Surface* window_surface_ptr, ground& ground_ptr);

  void setTimer();

  virtual void evolve() = 0;


  [[nodiscard]] std::chrono::time_point<std::chrono::system_clock> getTimer() const;


};