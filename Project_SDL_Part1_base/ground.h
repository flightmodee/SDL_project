//
// Created by xplo on 27/10/2021.
//
#pragma once

#include "timed_animal.h"

class ground {
private:
  std::vector<std::shared_ptr<moving_object>> animals_;
  std::vector<std::shared_ptr<timed_animal>> timed_animals_;

public:
  ground();
  ~ground() = default;
  void add_animal(const std::shared_ptr<moving_object>& a);
  void update();
  std::vector<std::shared_ptr<moving_object>>& getAnimals();
  void add_timed_animal(const std::shared_ptr<timed_animal>& a);



};