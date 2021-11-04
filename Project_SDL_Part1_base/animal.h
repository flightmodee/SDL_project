//
// Created by xplo on 27/10/2021.
//
#pragma once
#include "headers.h"
#include "declarations.hh"



class animal {
protected:
  SDL_Surface* window_surface_ptr_; // ptr to the surface on which we want the
                                    // animal to be drawn, also non-owning
  SDL_Surface* image_ptr_; // The texture of the sheep (the loaded image), use
                                    // load_surface_for
  double pos_x_;
  double pos_y_;
  double vel_x_;
  double vel_y_;
  int w_;
  int h_;
  std::set<std::string> properties_; //This set ise used to know more about the type, the status (alive or dead) of the animal
  std::chrono::time_point<std::chrono::system_clock> timer_;

 

public:
  animal(const std::string& file_path, SDL_Surface* window_surface_ptr);
  virtual ~animal() = default;

  void draw() const;

  virtual void move() = 0;
  double pos_x() const { return pos_x_; };
  double& pos_x() { return pos_x_; };
  double pos_y() const { return pos_y_; };
  double& pos_y() { return pos_y_; };
  double vel_x() const { return vel_x_; };
  double& vel_x() { return vel_x_; };
  double vel_y() const { return vel_y_; };
  double& vel_y() { return vel_y_; };

  int getw() const { return  w_; };
  int geth() const { return h_; };

  std::set<std::string> properties() const { return properties_; };
  std::set<std::string>& properties() { return properties_; };

  //virtual void interact(animal* otherAnimal, std::vector<std::shared_ptr<animal>>& new_sheeps) = 0;
  virtual void interact(std::shared_ptr<animal> otherAnimal, ground& ground) = 0;
  bool hasprop(std::string a);

  [[nodiscard]] std::chrono::time_point<std::chrono::system_clock>& getTimer();

};
