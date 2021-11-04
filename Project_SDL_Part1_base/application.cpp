//
// Created by xplo on 27/10/2021.
//

#include "application.h"
#include "animal.h"
#include "ground.h"
#include "sheep.h"
#include "wolf.h"
#include "shepherd.h"

application::application(unsigned int n_sheep, unsigned int n_wolf): 
    zoo_ground_(),
    last_ticks_(SDL_GetTicks()) {

    window_ptr_ =
        SDL_CreateWindow("My Zoo", SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, frame_width, frame_height, 0);
    if (!window_ptr_)
        throw std::runtime_error("application::application():" + std::string(SDL_GetError()));

    window_surface_ptr_ = SDL_GetWindowSurface(window_ptr_);

    if (!window_surface_ptr_)
        throw std::runtime_error("application::application():" + std::string(SDL_GetError()));
    zoo_ground_.set_ptr(window_surface_ptr_);


  srand((unsigned)time(nullptr));


  //SDL_Event e;
  //window_event_ = e;

  std::string sheep_path = "./media/sheep.png";
  std::string wolf_path = "./media/wolf.png";
  std::string shepherd_path = "./media/shepherd.png";

  //let's make things colorful.
  SDL_FillRect(window_surface_ptr_ ,nullptr, SDL_MapRGB(window_surface_ptr_->format,0,127,0));

  zoo_ground_.set_ptr(window_surface_ptr_);

  for (int i = 0; i < n_sheep; i++) {
    auto s = std::make_shared<sheep>(sheep_path, window_surface_ptr_);
    zoo_ground_.add_animal(s);
    s->draw();
  }

  for (int i = 0; i < n_wolf; i++){
    auto s = std::make_shared<wolf>(wolf_path, window_surface_ptr_);
    zoo_ground_.add_animal(s);
    s->draw();
  }
  auto s = std::make_shared<shepherd>(shepherd_path,window_surface_ptr_);
  zoo_ground_.add_animal(s);
  s->draw();

  SDL_UpdateWindowSurface(window_ptr_);

}

application::~application() {
  SDL_FreeSurface(window_surface_ptr_);
  SDL_DestroyWindow(window_ptr_);
  std::cout << "The application is no more." << std::endl;
}


int application::loop(unsigned period) {

  srand((unsigned)time(nullptr));

  Uint32 currentTime = 0;
  int lastTime = 0;
  auto zoo = zoo_ground_.getAnimals();

  while (currentTime <= period) {

    //This terminates the application, if we... try to close it
    while (SDL_PollEvent(&window_event_))
      if (window_event_.type == SDL_QUIT)
        return 0;

    SDL_FillRect(window_surface_ptr_ ,nullptr, SDL_MapRGB(window_surface_ptr_->format,0,127,0));
    zoo_ground_.update();
    currentTime = SDL_GetTicks();
    SDL_UpdateWindowSurface(window_ptr_);
    SDL_Delay((Uint32)frame_time);

  }
  return 1;
}