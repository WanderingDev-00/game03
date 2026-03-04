

#include"engine/core/game.h"

struct sdlstate
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer= nullptr;
	int logh, logw, width, height;

};


int main(int argc, char* argv[])
{

	Game& game = Game::getInstance();
	sdlstate state;
	TimeCalc& timer = TimeCalc::getInstance();
	TextureManager& texmgr = TextureManager::getInstance();

	state.width = 640;
	state.height = 320;


    game.getwindowsize(state.width, state.height);

	if (!game.initialize())
	{
		return -1;
	}
	texmgr.Load(state.renderer, "player_idle", "assets/player/player_idle.png");
	timer.getlasttime();
	game.run();

	game.cleanup(state.window, state.renderer);
	return 0;

}