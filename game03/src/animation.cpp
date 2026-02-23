#include "animtimer.h"

void animation::animtimerupdate(float deltatime)
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
             framewidth,
             frameheight };
}

// ✅ ADD: Configure which animation row + frames
void animation::setAnimation(int row, int totalFrames)
{
    if (currentrow != row) {
        currentrow = row;
        currentframe = 0;  // Reset frame when switching animation
        timer = 0.0f;
    }
    totalframes = totalFrames;
}