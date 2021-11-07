//
// Created by xplo on 27/10/2021.
//

#include "ground.h"
#include "headers.h"


ground::ground() : animals_{std::vector<std::shared_ptr<moving_object>>()} {
  timed_animals_ = std::vector<std::shared_ptr<timed_animal>>();
}

void ground::add_animal(const std::shared_ptr<moving_object>& a) {
  animals_.push_back(a);
}

void ground::add_timed_animal(const std::shared_ptr<timed_animal> &a){
  timed_animals_.push_back(a);
}

void ground::update(){


  std::shared_ptr<moving_object> a, b;

  for (int i = 0; i < animals_.size(); ++i){

    a = animals_[i];
    double xA = a->pos_x() + (a->get_w()) / 2;
    double yA = a->pos_y() + (a->get_h()) / 2;


      for (int j = 0; j < animals_.size(); ++j){

        b = animals_[j];
        if (a == b)
          continue;

        //calcul de la distance
        double xB = b->pos_x() + (b->get_w()) / 2;
        double yB = b->pos_y() + (b->get_h()) / 2;
        double dx = xB - xA;
        double dy = yB - yA;
        double distance = sqrt(dx * dx + dy * dy);

        a->interact(b, distance);
      }
  }

  for (auto& l : timed_animals_) {
    auto now = std::chrono::system_clock::now();
    auto delay = std::chrono::duration_cast<std::chrono::seconds>(now - l->getTimer()).count();

    if (l->hasProperty("lamb")) {
      if (delay > childhoodDuration)
        l->evolve();
    }
    else if (l->hasProperty("wolf"))
      if (delay > starvingDuration)
        l->evolve();
  }



  for (auto &d : animals_) {
    d->move();
    d->draw();
  }

}
std::vector<std::shared_ptr<moving_object>> &ground::getAnimals() {
  return animals_;
}
