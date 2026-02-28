#pragma once
#include<iostream>
#include"SDL3/SDL.h"
class Time
{
private: Uint64 currentTime, lastTime;
	   float deltatime;

public: void getlasttime();
	 void  gettime();
	 float getdeltatime();
	  
	    

}; 