//
// Created by xplo on 27/10/2021.
//

#include "headers.h"
#include "application.h"
#include "ground.h"
#include "sheep.h"
#include "wolf.h"

constexpr unsigned int childhoodDuration = 5;
constexpr std::string_view samy_sheep_path = "/home/xplo/ESIEE/cpp/Project_SDL_Part1_ABDOUCHE/media/sheep.png";
constexpr std::string_view samy_wolf_path = "/home/xplo/ESIEE/cpp/Project_SDL_Part1_ABDOUCHE/media/wolf.png";
constexpr std::string_view anh_my_sheep_path = "./media/sheep.png";
constexpr std::string_view anh_my_wolf_path = "./media/wolf.png";


application::application(unsigned int n_sheep, unsigned int n_wolf) {

  srand((unsigned)time(nullptr));

  window_ptr_ = SDL_CreateWindow("My Zoo", SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED, frame_width, frame_height, 0);

  window_surface_ptr_ = SDL_GetWindowSurface(window_ptr_);

  zoo_ground_ = ground();

  //SDL_Event e;
  //window_event_ = e;

  std::string sheep_path = "/home/xplo/ESIEE/cpp/Project_SDL_Part1_ABDOUCHE/media/sheep.png";
  std::string wolf_path = "/home/xplo/ESIEE/cpp/Project_SDL_Part1_ABDOUCHE/media/wolf.png";

  //std::string sheep_path = "./media/sheep.png";
  //std::string wolf_path = "./media/wolf.png";

  //let's make things colorful.
  SDL_FillRect(window_surface_ptr_ ,nullptr, SDL_MapRGB(window_surface_ptr_->format,0,127,0));

  auto sheep_prop = std::set<std::string>{"sheep", "adult"};
  for (int i = 0; i < n_sheep; i++) {
    auto s = std::make_shared<sheep>(sheep_path, window_surface_ptr_, sheep_prop);
    zoo_ground_.add_animal(s);
    s->draw();
  }

  for (int i = 0; i < n_wolf; i++){
    auto s = std::make_shared<wolf>(wolf_path, window_surface_ptr_);
    zoo_ground_.add_animal(s);
    s->draw();
  }
  SDL_UpdateWindowSurface(window_ptr_);

}

application::~application() {
  SDL_FreeSurface(window_surface_ptr_);
  SDL_DestroyWindow(window_ptr_);
  std::cout << "The application is no more." << std::endl;
}


int application::loop(unsigned period) {

  SDL_Surface* sheep_surface = load_surface_for(samy_sheep_path.data(), window_surface_ptr_);

  srand((unsigned)time(nullptr));

  Uint32 currentTime = 0;
  int lastTime = 0;
  auto& zoo = zoo_ground_.getAnimals();


  while (currentTime <= period) {

    int i = 0;
    //This terminates the application, if we... try to close it
    while (SDL_PollEvent(&window_event_))
      if (window_event_.type == SDL_QUIT)
        return 0;

    SDL_FillRect(window_surface_ptr_ ,nullptr, SDL_MapRGB(window_surface_ptr_->format,0,127,0));
    zoo_ground_.update();
    currentTime = SDL_GetTicks();


    //checking if lambs are past childhood
    for (auto& s : zoo){

      if (s->hasProp("lamb")) {

        auto now = std::chrono::system_clock::now();
        auto delay = std::chrono::duration_cast<std::chrono::seconds>(now - s->getTimer()).count();

        if (delay > childhoodDuration) {

          s->getw() *= 1.5;
          s->geth() *= 1.5;
          s->getImageSurface() = load_surface_for(samy_sheep_path.data(), window_surface_ptr_);
          s->properties().insert("sheep");
          s->properties().erase("lamb");

        }
      }
    }
    SDL_UpdateWindowSurface(window_ptr_);
    SDL_Delay((Uint32)frame_time);


  }
  return 1;
}