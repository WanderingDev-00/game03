#include "player.h"


//  This is what update() does for the player
void player::update(float deltaTime)
{
    playerpos(deltaTime);           // Update position based on input
    updateAnimation(deltaTime);     // Update animation frame
}

//  This is what draw() does for the player
void player::draw(SDL_Renderer* renderer)
{
    // Renderer will call this, passing the renderer
    // You'll draw the player here using the texture manager
    // (We'll show this part in gamerender.cpp instead)
}


void player::playerpos(float deltatime)
{
    const bool* keys = SDL_GetKeyboardState(NULL);
    bool moving = false;

    if (keys[SDL_SCANCODE_W]) {
        y -= speed * deltatime;
        currentAnimState = 2;
        moving = true;
    }
    if (keys[SDL_SCANCODE_S]) {
        y += speed * deltatime;
        currentAnimState = 3;
        moving = true;
    }
    if (keys[SDL_SCANCODE_A]) {
        x -= speed * deltatime;
        currentAnimState = 4;
        moving = true;
    }
    if (keys[SDL_SCANCODE_D]) {
        x += speed * deltatime;
        currentAnimState = 5;
        moving = true;
    }

    if (!moving) {
        currentAnimState = 1;
    }
}

void player::updateAnimation(float deltatime)
{
    playerAnim.animtimerupdate(deltatime);

    switch (currentAnimState) {
    case 1:
        playerAnim.setAnimation(0, 4);
        break;
    case 2:
        playerAnim.setAnimation(1, 4);
        break;
    case 3:
        playerAnim.setAnimation(2, 4);
        break;
    case 4:
        playerAnim.setAnimation(3, 4);
        break;
    case 5:
        playerAnim.setAnimation(4, 4);
        break;
    }
}