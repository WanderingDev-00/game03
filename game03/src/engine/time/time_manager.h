
#pragma once
#include<iostream>
#include"SDL3/SDL.h"
class TimeCalc
{
private: Uint64 currentTime, lastTime;
	   float deltatime;
	   TimeCalc() = default;

	   // Delete copy constructor and assignment operator
	   TimeCalc(const TimeCalc&) = delete;
	   TimeCalc& operator=(const TimeCalc&) = delete;

public:static TimeCalc& getInstance() {
	static TimeCalc instance;  // Created only once
	return instance;
}
	
	
	void getlasttime();
	  void  gettime();
	  float getdeltatime();



};