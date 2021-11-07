//
// Created by xplo on 07/11/2021.
//

#include "timed_animal.h"

timed_animal::timed_animal(const std::string& file_path, SDL_Surface* window_surface_ptr, ground& ground_ptr)
    : animal(file_path, window_surface_ptr, ground_ptr), timer_ {std::chrono::system_clock::now()}{}


void timed_animal::setTimer() {
  timer_ = std::chrono::system_clock::now();
}
std::chrono::time_point<std::chrono::system_clock> timed_animal::getTimer() const {
  return timer_;
}
