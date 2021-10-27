//
// Created by xplo on 27/10/2021.
//
#pragma once

#include "animal.h"
#include "headers.h"
#include "utils.h"

class ground {
private:
  std::vector<std::shared_ptr<animal>> animals_;

public:
  ground();
  ~ground() = default;
  void add_animal(const std::shared_ptr<animal>& a);
  void update() const;
  [[nodiscard]] std::vector<std::shared_ptr<animal>> getAnimals() const;
};