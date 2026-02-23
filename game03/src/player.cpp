#include "player.h"
#include "texturemanager.h"
#include "animtimer.h"
animation anim;
void updateplayer(player& play ,float deltatime)
{
	

	play.playerpos(deltatime);


}

void player::playerpos(float deltatime)
{
    const bool* keys = SDL_GetKeyboardState(NULL);
    bool moving = false; // Track if ANY key is pressed

    if (keys[SDL_SCANCODE_W]) {
        y -= speed * deltatime;
        playeranim = 2;
        moving = true;
    }
    if (keys[SDL_SCANCODE_S]) {
        y += speed * deltatime;
        playeranim = 3;
        moving = true;
    }
    if (keys[SDL_SCANCODE_A]) {
        x -= speed * deltatime;
        playeranim = 4;
        moving = true;
    }
    if (keys[SDL_SCANCODE_D]) {
        x += speed * deltatime;
        playeranim = 5;
        moving = true;
    }

    // If no keys are pressed, switch to Idle animation
    if (!moving) {
        playeranim = 1; // 1 = Idle
    }
}

void player::playeranimation(int playeranim)
{
    anim.getSrcRect();
}
