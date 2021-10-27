//
// Created by xplo on 27/10/2021.
//

#include "headers.h"
#include "ground.h"

ground::ground() : animals_{std::vector<std::shared_ptr<animal>>()}{}

void ground::add_animal(const std::shared_ptr<animal>& a) {
  animals_.push_back(a);
}

std::vector<std::shared_ptr<animal>> ground::getAnimals() const {
  return animals_;
}

void ground::update() const {
  for (const auto& a : animals_) {
    a->move();
    a->draw();
  }
}