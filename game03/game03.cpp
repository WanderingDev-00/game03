

#include"src/engine/core/game.h"

struct sdlstate
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	int logh, logw, width, height;

};


int main(int argc, char* argv[])
{

	Game game;
	sdlstate state;
	game.getwindowsize(state.width,state.height);

	if (!game.initialize(state.window, state.renderer))
	{
		return -1;
	}


	game.cleanup(state.window, state.renderer);
	return 0;

}