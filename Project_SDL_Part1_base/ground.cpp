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
    int xA = a->pos_x() + (a->getw()) / 2;
    int yA = a->pos_y() + (a->geth()) / 2;
    for (const auto& b : animals_) {
        if (a == b)
            continue;
        double xB = b->pos_x()+(b->getw())/2;
        double yB = b->pos_y() + (b->geth()) / 2;
        double dx = xB - xA;
        double dy = yB - yA;
        double distance = sqrt(dx * dx + dy * dy);
        double vAx = a->vel_x();
        double vAy = a->vel_y();
        double vBx = b->vel_x();
        double vBy = b->vel_y();
        if (distance < 100) {

            if (a->isSheep()) {
                a->interact(b.get());
            }

        }
            
    }
}
  for (const auto& a : animals_) {
    a->move();
    a->draw();
  }
}