#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include "entity.h"
#include "player.h"
#include "texturemanager.h"

class Gamerender
{
private:
    player play;
    TextureManager* texMgr = nullptr;
    std::vector<Entity*> entities;  // List of all entities

public:
    void init(TextureManager& texManager);
    void preparerenderer(SDL_Renderer* renderer);

    // THIS IS updateAll() - You need to code it
    void updateAll(float deltaTime);

    void drawAll(SDL_Renderer* renderer);

    player& getPlayer() { return play; }
};