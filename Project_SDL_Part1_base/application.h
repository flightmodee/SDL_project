//
// Created by xplo on 27/10/2021.
//
#pragma once
#include "Project_SDL1.h"
#include "ground.h"

class application {
private:
  // The following two are owning pointers.
  SDL_Window* window_ptr_;
  SDL_Surface* window_surface_ptr_;
  SDL_Event window_event_;
  ground zoo_ground_;
  SDL_Surface* score_surface_;
  SDL_Rect score_rect_;
  unsigned int score_;
  TTF_Font* font_ = TTF_OpenFont("/home/xplo/ESIEE/cpp/Project_SDL_Part1_ABDOUCHE/media/Cotton Butter.ttf", 40);


public:
  application(unsigned n_sheep, unsigned n_wolf); // Ctor
  ~application();                              // dtor

  int loop(unsigned period); // main loop of the application.
                             // this ensures that the screen is updated
                             // at the correct rate.
                             // See SDL_GetTicks() and SDL_Delay() to enforce a
                             // duration the application should terminate after
                             // 'period' seconds

};