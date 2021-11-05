//
// Created by xplo on 27/10/2021.
//

#include "ground.h"
#include "animal.h"
#include "headers.h"

ground::ground() : animals_{std::vector<std::shared_ptr<animal>>()}{
  lambs_ = std::vector<std::shared_ptr<sheep>>();
}

void ground::add_animal(const std::shared_ptr<animal>& a) {
  animals_.push_back(a);
}

std::vector<std::shared_ptr<animal>> ground::getAnimals() const {
  return animals_;
}

void ground::update(){


  std::shared_ptr<animal> a, b;

  for (int i = 0; i < animals_.size(); ++i){

    a = animals_[i];
    double xA = a->pos_x() + (a->getw()) / 2;
    double yA = a->pos_y() + (a->geth()) / 2;


      for (int j = 0; j < animals_.size(); ++j){

        b = animals_[j];
        if (a == b)
          continue;

        //calcul de la distance
        double xB = b->pos_x() + (b->getw()) / 2;
        double yB = b->pos_y() + (b->geth()) / 2;
        double dx = xB - xA;
        double dy = yB - yA;
        double distance = sqrt(dx * dx + dy * dy);

          if (distance < 30)
            a->interact(b, *this);
      }
  }

  for (auto &c : animals_) {
    c->move();
    c->draw();
  }

}



std::vector<std::shared_ptr<animal>>& ground::getAnimals() {
  return animals_;
}
std::vector<std::shared_ptr<sheep>> ground::getLambs() const {
  return lambs_;
}
std::vector<std::shared_ptr<sheep>> &ground::getLambs() {
  return lambs_;
}
