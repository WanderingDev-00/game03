#include"input_manager.h"

void input::eventhandler()
{
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_EVENT_QUIT) running = false;
	}
}