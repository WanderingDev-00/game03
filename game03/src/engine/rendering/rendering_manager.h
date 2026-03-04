#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include "engine/entity.h"
#include "game/player/player.h"
#include "texturemanager.h"

class Gamerender
{
private:
    player play;
    TextureManager* texMgr = nullptr;
    std::vector<Entity*> entities;  // List of all entities
    // Private constructor - can't create instances from outside
    Gamerender() = default;

    // Delete copy constructor and assignment operator
    Gamerender(const Gamerender&) = delete;
    Gamerender& operator=(const Gamerender&) = delete;


public:
    static Gamerender& getInstance() {   //making sure only single instance
        static Gamerender instance;  // Created only once
        return instance;
    }
    void init(TextureManager& texManager);
    void preparerenderer(SDL_Renderer* renderer);

    // THIS IS updateAll() - You need to code it
    void updateAll(float deltaTime);

    void drawAll(SDL_Renderer* renderer);

    player& getPlayer() { return play; }
};