#pragma once
#include <SDL3/SDL.h>

class animation
{
private:
    float timer = 0.0f;
    float speed = 0.1f;      // Duration per frame
    float currentframe = 0;
    float totalframes = 4;     // How many frames in this animation
    float framewidth = 32;     // Size of ONE frame
    float frameheight = 32;
    float currentrow = 0;   // Which row in spritesheet


public:
    void animtimerupdate(float deltatime);
    SDL_FRect getSrcRect()const ;  // because const issue when used and to make sire no change in data

    //  Methods to configure animation
    void setAnimation(int row, int totalFrames);
    int getCurrentFrame() const { return currentframe; }
    int getTotalFrames() const { return totalframes; }
};  