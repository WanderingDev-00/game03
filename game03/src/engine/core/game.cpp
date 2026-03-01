#include"game.h"


bool Game::initialize(SDL_Window* window, SDL_Renderer* renderer)

{

	bool initsuccess = true;
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "unable to intialize", SDL_GetError(), nullptr);
		cleanup(window, renderer);
		return initsuccess = false;
	}
	window = SDL_CreateWindow("game03", width, height, SDL_WINDOW_RESIZABLE);
	if (!window)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "unable to create window", SDL_GetError(), nullptr);
		cleanup(window, renderer);
		return initsuccess = false;
	}
	renderer = SDL_CreateRenderer(window, nullptr);
	if (!renderer)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "unable to create renderer", SDL_GetError(), nullptr);
		cleanup(window, renderer);
		return initsuccess = false;
	}
	logw = 640;
	logh = 320;
	SDL_SetRenderLogicalPresentation(renderer, logw, logh, SDL_LOGICAL_PRESENTATION_DISABLED);

	return initsuccess;

}

void Game::cleanup(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}