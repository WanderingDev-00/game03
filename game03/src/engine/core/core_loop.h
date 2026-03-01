#pragma once
#include<SDL3/SDL.h>
#include"game.h"
#include"engine/time/time_manager.h"
class coreloop : Game
{
private: TimeCalc& timer = TimeCalc::getInstance();

};