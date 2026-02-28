

#include"src/engine/core/game.h"
#include"src/engine/core/time_manager.h"

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
	Time t;
	game.getwindowsize(state.width,state.height);
	t.getlasttime();

	if (!game.initialize(state.window, state.renderer))
	{
		return -1;
	}


	game.cleanup(state.window, state.renderer);
	return 0;

}