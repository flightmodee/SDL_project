
#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "animal.h"
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>

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

/*

class animal {
protected:
  SDL_Surface* window_surface_ptr_; // ptr to the surface on which we want the
                                    // animal to be drawn, also non-owning
  SDL_Surface* image_ptr_; // The texture of the sheep (the loaded image), use
                           // load_surface_for
  unsigned int x_;
  unsigned int y_;
  bool horizontal_direction_; //These booleans are used to represent the horizontal and vertical directions of an animal's movement.
                              // If they're true, they respectively indicate the animal is moving downwards and rightwards, and vice versa.
  bool vertical_direction_;

public:
  animal(const std::string& file_path, SDL_Surface* window_surface_ptr, bool horizontal_direction, bool vertical_direction);
  virtual ~animal() = default;

  void draw() const;

  virtual void move() = 0;

};*/



/** CLASS SHEEP, DERIVED FROM ANIMAL **/
/*
class sheep : public animal {
public:
  sheep(const std::string& file_path, SDL_Surface* window_surface_ptr);
  ~sheep() override;
  void move() override;
  // implement functions that are purely virtual in base class
};*/

/** CLASS WOLF, DERIVED FROM ANIMAL **/

/*
class wolf : public animal {
public:
  wolf(const std::string& file_path, SDL_Surface* window_surface_ptr);
  ~wolf() override;
  void move() override;
};*/



/** CLASS GROUND, WHERE ALL THE ANIMALS "LIVE" **/
/*
class ground {
private:
  std::vector<std::shared_ptr<animal>> animals_;

public:
  ground();
  ~ground() = default;
  void add_animal(const std::shared_ptr<animal>& a);
  void update() const;
  [[nodiscard]] std::vector<std::shared_ptr<animal>> getAnimals() const;
};*/

// The application class, which is in charge of generating the window
/*
class application {
private:
  // The following two are owning pointers.
  SDL_Window* window_ptr_;
  SDL_Surface* window_surface_ptr_;
  SDL_Event window_event_;
  ground zoo_ground_;

public:
  application(unsigned n_sheep, unsigned n_wolf); // Ctor
  ~application();                              // dtor

  int loop(unsigned period); // main loop of the application.
                             // this ensures that the screen is updated
                             // at the correct rate.
                             // See SDL_GetTicks() and SDL_Delay() to enforce a
                             // duration the application should terminate after
                             // 'period' seconds

};*/