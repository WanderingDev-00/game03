#include"time_manager.h"
void Time::gettime()
{
	 currentTime = SDL_GetTicks();
	 deltatime = (currentTime - lastTime) / 1000.0f;
	lastTime = currentTime;
}


float Time:: getdeltatime()
{
	gettime();
	return deltatime;
}
void Time::getlasttime()
{
	lastTime = SDL_GetTicks();
}