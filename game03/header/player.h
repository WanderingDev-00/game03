#pragma once
#include <SDL3/SDL.h>
#include "entity.h"
#include "animtimer.h"
#include <SDL3/SDL_render.h>
#include"texturemanager.h"

class player : public Entity  // INHERITS from Entity
{
private:
    float playerx =450.0f;
    float playery = 450.0f;
    float speed = 100.0f;
    int currentAnimState = 1;
    animation playerAnim;
    TextureManager* texmgr;
    float playerinarea=0;


public:
    // IMPLEMENT Entity's virtual methods
    void updateEntity(float deltaTime) override;
    void draw(SDL_Renderer* renderer) override;
    float getX() const override { return playerx; }
    float getY() const override { return playery; }
    std::string getType() const override { return "player"; }

    // Keep your helper methods
    void playerpos(float deltatime);
    void updateAnimation(float deltatime);
    SDL_Rect getAnimationFrame()const { return playerAnim.getSrcRect(); }
    float giveplayerareano()const { return playerinarea; }
};