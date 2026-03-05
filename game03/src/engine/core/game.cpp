#include"game.h"


bool Game::initialize(SDL_Renderer * Renderer , SDL_Window* Window)

{

	bool initsuccess = true;
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "unable to intialize", SDL_GetError(), nullptr);
		cleanup(Window, Renderer);
		return initsuccess = false;
	}
	Window = SDL_CreateWindow("game03", width, height, SDL_WINDOW_RESIZABLE);
	if (!Window)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "unable to create window", SDL_GetError(), nullptr);
		cleanup(Window, Renderer);
		return initsuccess = false;
	}
	Renderer = SDL_CreateRenderer(Window, nullptr);
	if (!Renderer)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "unable to create renderer", SDL_GetError(), nullptr);
		cleanup(Window, Renderer);
		return initsuccess = false;
	}
	logw = 640;
	logh = 320;
	SDL_SetRenderLogicalPresentation(renderer, logw, logh, SDL_LOGICAL_PRESENTATION_DISABLED);
	window = Window;
	renderer = Renderer;
	

	return initsuccess ;

}

void Game::cleanup(SDL_Window* window, SDL_Renderer* renderer)
{
	texmgr.ALLTexclear();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
void Game::run(SDL_Renderer* Ren)
{

	running = true;
	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) running = false;
		}
		deltatime = timer.getdeltatime();
		gamerender.updateAll(deltatime);
		gamerender.preparerenderer(Ren);
		gamerender.drawAll(Ren);
		SDL_RenderPresent(Ren);// need this no matter what 

	}

}