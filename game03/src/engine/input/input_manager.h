#pragma once
#include<SDL3/SDL.h>



class input
{
private:SDL_Event event;
	   bool running = false;
public:
	void eventhandler();


};