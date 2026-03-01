

#include"engine/core/game.h"

struct sdlstate
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	int logh, logw, width, height;

};


int main(int argc, char* argv[])
{

	Game& game = Game::getInstance();
	sdlstate state;
	TimeCalc& timer = TimeCalc::getInstance();

	game.getwindowsize(state.width, state.height);

	if (!game.initialize(state.window, state.renderer))
	{
		return -1;
	}

	timer.getlasttime();
	game.run();

	game.cleanup(state.window, state.renderer);
	return 0;

}