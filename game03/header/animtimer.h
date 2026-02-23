#pragma once
#include <SDL3/SDL.h>

class animation
{
private:
    float timer = 0.0f;
    float animspeed = 0.5f;      // Duration per frame
    int currentframe = 0;
    int totalframes = 4;     // How many frames in this animation
    int framewidth = 32;     // Size of ONE frame
    int frameheight = 32;
    int currentrow = 0;      // Which row in spritesheet

public:
    void animtimerupdate(float deltatime);
    SDL_Rect getSrcRect() const ;
     
    //  Methods to configure animation 
    void setAnimation(int row, int totalFrames);
    int getCurrentFrame() const { return currentframe; }
    int getTotalFrames() const { return totalframes; }
};