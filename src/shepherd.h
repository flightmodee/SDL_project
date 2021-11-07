//
// Created by xplo on 27/10/2021.
//
#pragma once
#include "Project_SDL1.h"
#include "playable_character.h"

class shepherd : public playable_character {
private:
	SDL_Event event_;
public:
	shepherd(const std::string& file_path, SDL_Surface* window_surface_ptr, ground& ground_ptr);
	~shepherd() override;
	void move() override;
	// implement functions that are purely virtual in base class
	void interact(std::shared_ptr<moving_object> otherAnimal) override;
};