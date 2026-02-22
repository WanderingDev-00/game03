#include "player.h"
void updateplayer(float deltatime)
{
	player play;

	play.playerpos();


}

void player::playerpos(float deltatime)
{
	const bool* keys = SDL_GetKeyboardState(NULL);

	if (keys[SDL_SCANCODE_W])
	{
		y -= speed * deltatime;

		playeranim = 2; // this says what plaer animation to run
	}
	if (keys[SDL_SCANCODE_S])
	{
		y += speed * deltatime;
		playeranim = 3;
	}
	if (keys[SDL_SCANCODE_A])
	{
		x -= speed * deltatime;
		playeranim = 4;
	}
	if (keys[SDL_SCANCODE_D])
	{
		x += speed * deltatime;
		playeranim = 5;
	}



}
