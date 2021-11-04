//
// Created by xplo on 27/10/2021.
//
#pragma once

#include "headers.h"
#include "Project_SDL1.h"
#include "declarations.hh"

class ground {
private:
  std::vector<std::shared_ptr<animal>> animals_;

public:
  ground();
  ~ground() = default;
  void add_animal(const std::shared_ptr<animal>& a);
  void update();
  [[nodiscard]] std::vector<std::shared_ptr<animal>> getAnimals() const;
  std::vector<std::shared_ptr<animal>>& getAnimals();
};