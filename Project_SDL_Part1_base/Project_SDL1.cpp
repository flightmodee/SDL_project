#include "headers.h"
#include <algorithm>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

void init() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
    throw std::runtime_error("init():" + std::string(SDL_GetError()));

  // Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags))
    throw std::runtime_error("init(): SDL_image could not initialize! "
                             "SDL_image Error: " +
                             std::string(IMG_GetError()));
}

SDL_Surface* load_surface_for(const std::string& path, SDL_Surface* window_surface_ptr) {

  if (!window_surface_ptr){
    std::cout << "No valid window surface passed as argument. Bad." << endl;
    return (nullptr);
  }

  //int length = (int)path.length();
  //char new_file_path[length];
  //strcpy(new_file_path, path.c_str()); // we have successfully converted our string into an array of char.

  SDL_Surface* surf = SDL_ConvertSurface(IMG_Load(path.c_str()), window_surface_ptr->format, 0);
  if (!surf){
    std::cout << "Error during creation of surface." << std::endl;
    return (nullptr);
  }

  return (surf);
}

void constrained_linear_move_(double& x, double& y, double& vx, double& vy) {
    x += (frame_time * vx);
    y += (frame_time * vy);

    // Enforce boundaries
    constexpr double h_m = frame_boundary;
    constexpr double w_m = frame_boundary;
    constexpr double h_M = frame_height - frame_boundary;
    constexpr double w_M = frame_width - frame_boundary;

    if (x < w_m) {
        x = w_m;
        vx = std::abs(vx);
    }

    if (y < w_m) {
        y = w_m;
        vy = std::abs(vy);
    }

    if (x > w_M) {
        x = w_M;
        vx = -std::abs(vx);
    }

    if (y > h_M) {
        y = h_M;
        vy = -std::abs(vy);
    }
}