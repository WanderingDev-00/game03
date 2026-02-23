#pragma once
#include"tickupdate.h"
#include<SDL3/SDL.h>
#include"animtimer.h"

class player
{
private: float x, y;
	   float speed = 200.0f;
	   int playeranim;  // this says what plaer animation to run

public:
	void playerpos(float deltatime);

	void playeranimation(int playeranim);


};