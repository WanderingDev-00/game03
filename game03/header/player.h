#pragma once
#include <SDL3/SDL.h>
#include "entity.h"
#include "animtimer.h"

class player : public Entity  // INHERITS from Entity
{
private:
    float x = 100.0f;
    float y = 100.0f;
    float speed = 200.0f;
    int currentAnimState = 1;
    animation playerAnim;

public:
    // IMPLEMENT Entity's virtual methods
    void update(float deltaTime) override;
    void draw(SDL_Renderer* renderer) override;
    float getX() const override { return x; }
    float getY() const override { return y; }
    std::string getType() const override { return "player"; }

    // Keep your helper methods
    void playerpos(float deltatime);
    void updateAnimation(float deltatime);
    SDL_Rect getAnimationFrame() const { return playerAnim.getSrcRect(); }
};