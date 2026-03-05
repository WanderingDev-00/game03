

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
	Gamerender& gamerenderer = Gamerender::getInstance();

	state.width = 640;
	state.height = 320;


    game.getwindowsize(state.width, state.height);

	if (!game.initialize(state.renderer,state.window))
	{
		return -1;
	}
	gamerenderer.init();
	state.renderer = game.getrenderer(); //as renderer is everywere they should be common so its being used  i will try find a different way
	state.window = game.getwindow();
	texmgr.Load(state.renderer, "player_idle", "assets/player/player_idle.png");
	timer.getlasttime();
	game.run(state.renderer);

	game.cleanup(state.window, state.renderer);
	return 0;

}