#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>
#include<SDL3_image/SDL_image.h>
#include<SDL3/SDL_render.h>
#include "texturemanager.h"
#include "player.h"
#include"tickupdate.h"
#include"gamerender.h"

struct sdlstate //holds variable for sdl init and refer and use
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	int logh, logw, width, height;

};
void cleanup(sdlstate& state);
bool init(sdlstate& state);





int main(int argc, char* argv[])
{

	sdlstate state;
	state.width = 1600;
	state.height = 800;
	if (!init(state))
	{
		return -1;
	}
	

	TextureManager texMgr;
	player play;
	Gamerender render;

	

	Uint64 lastTime = SDL_GetTicks(); // For deltatime calculation
	bool running = true;

	while (running) {
		// --- 1. EVENT HANDLING ---
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) running = false;
		}

		// --- 2. LOGIC / UPDATE ---
		Uint64 currentTime = SDL_GetTicks();
		float deltatime = (currentTime - lastTime) / 1000.0f;
		lastTime = currentTime;
		update(play, deltatime);


		// --- 3. RENDERING ---
		render.preparerenderer(state.renderer);

		// Draw 
		render.rendererdraw(state.renderer);

		SDL_RenderPresent(state.renderer);
	}

	// --- CLEANUP ---
	
	texMgr.ALLTexclear();
	cleanup(state);
	return 0;

}

bool init(sdlstate& state)

{
	bool initsuccess = true;
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "unable to intialize", SDL_GetError(), nullptr);
		cleanup(state);
		return initsuccess = false;
	}
	state.window = SDL_CreateWindow("game03", state.width, state.height, SDL_WINDOW_RESIZABLE);
	if (!state.window)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "unable to create window", SDL_GetError(), nullptr);
		cleanup(state);
		return initsuccess = false;
	}
	state.renderer = SDL_CreateRenderer(state.window, nullptr);
	if (!state.renderer)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "unable to create renderer", SDL_GetError(), nullptr);
		cleanup(state);
		return initsuccess = false;
	}
	state.logw = 640;
	state.logh = 320;
	SDL_SetRenderLogicalPresentation(state.renderer, state.logw, state.logh, SDL_LOGICAL_PRESENTATION_LETTERBOX);
	return initsuccess;
}
void cleanup(sdlstate& state)
{
	SDL_DestroyRenderer(state.renderer);
	SDL_DestroyWindow(state.window);
	SDL_Quit();
}
