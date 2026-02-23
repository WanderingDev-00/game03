#include "player.h"
#include "texturemanager.h"
#include"animtimer.h"

//  This is what update() does for the player
void player::updateEntity(float deltaTime)
{
    playerpos(deltaTime);           // Update position based on input
    updateAnimation(deltaTime); 
   // SDL_Log("updatesucess");
    // Update animation frame
}

//  This is what draw() does for the player
void player::draw(SDL_Renderer* renderer)
{
    if (currentAnimState == 1)
    {
        SDL_Texture* ptex  = texmgr.gettex("player_Idle");
        SDL_Rect srcRect = getAnimationFrame();
        SDL_FRect fr = { (float)srcRect.x, (float)srcRect.y, (float)srcRect.w, (float)srcRect.h };
        SDL_FRect destRect = { playerx,playery,32,32
        };
        
        SDL_RenderTexture(renderer, ptex, &fr , &destRect);
     }

   
   // Adjust height by scale if needed

}


void player::playerpos(float deltatime)
{
    const bool* keys = SDL_GetKeyboardState(NULL);
    bool moving = false;

    if (keys[SDL_SCANCODE_W]) {
        playery -= speed * deltatime;
        currentAnimState = 2;
        moving = true;
    }
    if (keys[SDL_SCANCODE_S]) {
       playery += speed * deltatime;
        currentAnimState = 3;
        moving = true;
    }
    if (keys[SDL_SCANCODE_A]) {
        playerx -= speed * deltatime;
        currentAnimState = 4;
        moving = true;
    }
    if (keys[SDL_SCANCODE_D]) {
        playerx += speed * deltatime;
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