#include"time_manager.h"
void TimeCalc::gettime()
{
	currentTime = SDL_GetTicks();
	deltatime = (currentTime - lastTime) / 1000.0f;
	lastTime = currentTime;
}


float TimeCalc::getdeltatime()
{
	gettime();
	return deltatime;
}
void TimeCalc::getlasttime()
{
	lastTime = SDL_GetTicks();
}