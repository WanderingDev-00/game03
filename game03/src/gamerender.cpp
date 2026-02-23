#include "gamerender.h"
#include"player.h"
#include"tickupdate.h"
#include"texturemanager.h"
#include"animtimer.h"

player play;



void Gamerender:: preparerenderer(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 225, 0, 225, 255); // Pink background
	SDL_RenderClear(renderer);
}

void Gamerender::rendererdraw(SDL_Renderer* renderer)
{


	play.playeranimation(playeranim);
	

	

}