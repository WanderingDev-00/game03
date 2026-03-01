#include"core_loop.h"

void Game::run()
{
	
	running = true;
	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) running = false;
		}
		timer.getdeltatime();

	}

}