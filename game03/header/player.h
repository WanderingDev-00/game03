#pragma once
#include"tickupdate.h"
#include<SDL3/SDL.h>
#include"animtimer.h"
#include"entity.h"

class player : public Entity
{
private: float x, y;
	     float speed = 200.0f;
	     animation playeranim; 
		 int currentanimationstate = 1;// this says what player animation to run
public:
	void update(float deltaTime) override;
	void draw(SDL_Renderer* renderer) override;
	float getX() const override { return x; }
	float getY() const override { return y; }
	std::string getType() const override { return "player"; }
	void playerpos(float deltatime);

    void playeranimation(float deltatime);
	SDL_Rect getanimationframe()const { return playeranim.getSrcRect(); }


};