#pragma once
#include<SDL3/SDL.h>
#include"tickupdate.h"


class Gamerender
{
private:
	  
public:
	void preparerenderer(SDL_Renderer* renderer);
	void rendererdraw(SDL_Renderer* renderer);

	};    