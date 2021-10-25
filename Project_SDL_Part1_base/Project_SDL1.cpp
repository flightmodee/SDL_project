#include "Project_SDL1.h"
#include <algorithm>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

void init() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
    throw std::runtime_error("init():" + std::string(SDL_GetError()));

  // Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags))
    throw std::runtime_error("init(): SDL_image could not initialize! "
                             "SDL_image Error: " +
                             std::string(IMG_GetError()));
}

namespace {
// Defining a namespace without a name -> Anonymous workspace
// Its purpose is to indicate to the compiler that everything
// inside of it is UNIQUELY used within this source file.

SDL_Surface* load_surface_for(const std::string& path, SDL_Surface* window_surface_ptr) {

  if (!window_surface_ptr){
    std::cout << "No valid window surface passed as argument. Bad." << endl;
    return (nullptr);
  }

  int length = (int)path.length();
  char new_file_path[length];
  strcpy(new_file_path, path.c_str()); // we have successfully converted our string into an array of char.

  SDL_Surface* surf = SDL_ConvertSurface(IMG_Load(new_file_path), window_surface_ptr->format, 0);
  if (!surf){
    std::cout << "Error during creation of surface." << std::endl;
    return (nullptr);
  }

  return (surf);
}
} // namespace


/***** Implementation of the member functions of the animal class. ******/
animal::animal(const std::string &file_path, SDL_Surface *window_surface_ptr, bool horizontal_direction, bool vertical_direction)
    : window_surface_ptr_{window_surface_ptr}, horizontal_direction_{horizontal_direction}, vertical_direction_{vertical_direction}{

  image_ptr_ = load_surface_for(file_path, window_surface_ptr);

  //Let's make sure our animals spawn within the boundaries of our zoo.
  x_ = rand() % (frame_width - frame_boundary - image_ptr_->w) + frame_boundary;
  y_ = rand() % (frame_height - frame_boundary - image_ptr_->h) + frame_boundary;

}

void animal::draw() const{

  if (window_surface_ptr_ == nullptr || image_ptr_ == nullptr){
    std::cout << "pointers aren't ok, bro, do something";
    return;
  }

  //These two next lines are used to get rid of the PNG backgrounds
  Uint32 color_key = SDL_MapRGB(image_ptr_->format, 0, 0, 0);
  SDL_SetColorKey(image_ptr_, SDL_TRUE, color_key);
  SDL_Rect sheep_rect;
  sheep_rect.x = x_;
  sheep_rect.y = y_;

  SDL_BlitSurface(image_ptr_, nullptr, window_surface_ptr_, &sheep_rect);
}




/** Implementation of the member functions of the sheep class **/

sheep::sheep(const std::string& file_path, SDL_Surface* window_surface_ptr) : animal(file_path, window_surface_ptr, true, true){}

void sheep::move(){

  int surface_width = image_ptr_->clip_rect.w;
  int surface_height = image_ptr_->clip_rect.h;

  if (y_ >= frame_height - frame_boundary - surface_height)
    vertical_direction_ = false;

  if (y_ <= frame_boundary)
    vertical_direction_ = true;

  if (x_ >= frame_width - frame_boundary - surface_width)
    horizontal_direction_ = false;

  if (x_ <= frame_boundary)
    horizontal_direction_ = true;

  if (vertical_direction_)
    y_+=1;
  if (!vertical_direction_)
    y_-=1;

  if (horizontal_direction_)
    x_+=1;

  if (!horizontal_direction_)
    x_-=1;

}

sheep::~sheep() {
  SDL_FreeSurface(image_ptr_);
  std::cout << "Oh me, oh my, a sheep has been destroyed, whatever shall we do?" << std::endl;
}

/** Implementation of the member functions of the wolf class **/
wolf::wolf(const std::string& file_path, SDL_Surface* window_surface_ptr) : animal(file_path, window_surface_ptr, false, false){}


void wolf::move(){

  int surface_width = image_ptr_->clip_rect.w;
  int surface_height = image_ptr_->clip_rect.h;

  if (y_ >= frame_height - frame_boundary - surface_height)
    vertical_direction_ = false;

  if (y_ <= frame_boundary)
    vertical_direction_ = true;

  if (x_ >= frame_width - frame_boundary - surface_width)
    horizontal_direction_ = false;

  if (x_ <= frame_boundary)
    horizontal_direction_ = true;

  if (vertical_direction_)
    y_+=1;
  else
    y_-=1;

  if (horizontal_direction_)
    x_+=1;
  else
    x_-=1;

}

wolf::~wolf() {
  std::cout << "A wolf is gone. Good riddance, it'd prey on our precious sheep." << std::endl;
  SDL_FreeSurface(image_ptr_);
}

/** Implementation of the member functions of the ground class **/

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


/** Implementation of the member functions of the application class **/

application::application(unsigned int n_sheep, unsigned int n_wolf) {

  srand((unsigned)time(nullptr));

  window_ptr_ = SDL_CreateWindow("My Zoo", SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED, frame_width, frame_height, 0);

  window_surface_ptr_ = SDL_GetWindowSurface(window_ptr_);

  zoo_ground_ = ground();

  SDL_Event e;
  window_event_ = e;

  std::string sheep_path = "whatever_it_is/Project_SDL_Part1_base/media/sheep.png";
  std::string wolf_path = "whatever_it_is/Project_SDL_Part1_base/media/wolf.png";


  //let's make things colorful.
  SDL_FillRect(window_surface_ptr_ ,nullptr, SDL_MapRGB(window_surface_ptr_->format,0,127,0));

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


