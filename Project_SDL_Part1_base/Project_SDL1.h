#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>

// Definitions
constexpr double frame_rate = 60.0; // refresh rate
constexpr double frame_time = 1. / frame_rate;
constexpr unsigned frame_width = 1400; // Width of window in pixel
constexpr unsigned frame_height = 900; // Height of window in pixel
// Minimal distance of animals to the border
// of the screen
constexpr unsigned frame_boundary = 100;



// Helper function to initialize SDL
void init();
SDL_Surface* load_surface_for(const std::string& path, SDL_Surface* window_surface_ptr);
void constrained_linear_move_(double& x, double& y, double& vx, double& vy);
