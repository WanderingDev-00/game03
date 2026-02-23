#include "animtimer.h"

void animation:: animtimerupdate(float deltatime)
{
	timer += deltatime;
	if (timer >= speed)
	{
		timer -= speed;
		currentframe++;
	}
	
	if (currentframe >= totalframes)
	{
		currentframe = 0;
	}
}
SDL_Rect animation::getSrcRect()
{
	return { currentframe * framewidth,
	currentrow * frameheight,
	framewidth, frameheight
	};

}