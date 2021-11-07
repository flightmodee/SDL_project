//
// Created by xplo on 27/10/2021.
//

#include "application.h"
#include "animal.h"
#include "ground.h"
#include "headers.h"
#include "sheep.h"
#include "shepherd.h"
#include "shepherd_dog.h"
#include "wolf.h"

application::application(unsigned int n_sheep, unsigned int n_wolf) {

  /**************** INITIALIZING OUR PROPERTIES ************************/
  srand((unsigned)time(nullptr));

  window_ptr_ = SDL_CreateWindow("My Zoo", SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED, frame_width, frame_height, 0);

  window_surface_ptr_ = SDL_GetWindowSurface(window_ptr_);

  zoo_ground_ = ground();

  TTF_Font* font = TTF_OpenFont("/home/xplo/ESIEE/cpp/Project_SDL_Part1_ABDOUCHE/media/Cotton Butter.ttf", 40);


  score_rect_.x = 0;
  score_rect_.y = 0;

  score_ = n_sheep;

  score_surface_ = TTF_RenderText_Blended(font, std::to_string(score_).c_str(), black);

  /****************** FILLING OUR GROUND ****************************/


  //let's make things colorful.
  SDL_FillRect(window_surface_ptr_ ,nullptr, SDL_MapRGB(window_surface_ptr_->format,0,127,0));

  auto sheep_prop = std::set<std::string>{"sheep", "adult"};
  auto wolf_prop = std::set<std::string>{"wolf"};
  for (int i = 0; i < n_sheep; i++) {
    auto s = std::make_shared<sheep>(samy_sheep_path.data(), window_surface_ptr_, sheep_prop, zoo_ground_);
    zoo_ground_.add_timed_animal(s);
    zoo_ground_.add_object(s);
    s->draw();
  }

  for (int i = 0; i < n_wolf; i++) {
    auto s = std::make_shared<wolf>(samy_wolf_path.data(), window_surface_ptr_,
                                    zoo_ground_);
    zoo_ground_.add_object(s);
    zoo_ground_.add_timed_animal(s);
  }

  auto shep = std::make_shared<shepherd>(samy_shepherd_path.data(), window_surface_ptr_);
  zoo_ground_.add_object(shep);
  shep->draw();

  auto dog = std::make_shared<shepherd_dog>(samy_doggo_path.data(), window_surface_ptr_, zoo_ground_, shep);
  zoo_ground_.add_object(dog);
  dog->draw();
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
  auto& zoo = zoo_ground_.getObjects();


  while (currentTime <= period) {

    //This terminates the application, if we... try to close it
    while (SDL_PollEvent(&window_event_))
      if (window_event_.type == SDL_QUIT)
        return 0;

    SDL_FillRect(window_surface_ptr_ ,nullptr, SDL_MapRGB(window_surface_ptr_->format,0,127,0));
    zoo_ground_.update();
    currentTime = SDL_GetTicks();


    auto wolf_number = std::count_if(std::begin(zoo), std::end(zoo), [] (const std::shared_ptr<moving_object>& obj) {return obj->hasProperty("wolf");});

    score_ = zoo.size() - wolf_number - 2; //discarding the shepherd and the dog
    score_surface_ = TTF_RenderText_Blended(font_, std::to_string(score_).c_str(), black);
    SDL_BlitSurface(score_surface_, nullptr, window_surface_ptr_, &score_rect_);
    SDL_UpdateWindowSurface(window_ptr_);
    SDL_Delay((Uint32)frame_time);


  }
  return 1;
}