#include "textureloader.h"


void loadAreatex::loadAreaTexture(SDL_Renderer* renderer)
{
	loadDecide();

	playerLoadout(renderer);


	//if (area == 1)

	//if (area == 2)
}

void loadAreatex::loadDecide()
{
	area = play.giveplayerareano();
}

void loadAreatex::playerLoadout(SDL_Renderer* renderer)
{
	texMgr.Load(renderer,"Player_Idle","assets/player/player_idle.png");
}