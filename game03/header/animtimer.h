
#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

class animation
{private: float timer = 0.0f;
float speed = 0.1f;    // Duration of each frame
int currentframe = 0;
int totalframes = 1;

// Layout (The "Dealer" info)
int framewidth = 32;   // Size of a single frame
int frameheight = 32;
int currentrow = 0;

public: void animtimerupdate(float deltatime);
	  SDL_Rect getSrcRect();
};