#include "gamerender.h"


void Gamerender::init(TextureManager& texManager)
{
    texMgr = &texManager;

    //  Add player to entity list
    entities.push_back(&play);
}

void Gamerender::preparerenderer(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 225, 0, 225, 255);
    SDL_RenderClear(renderer);
}

//  Update all entities
void Gamerender::updateAll(float deltaTime)
{
    for (auto entity : entities) {
        entity->updateEntity(deltaTime);  //  Calls player::update()
    }
}

//  Draw all entities
void Gamerender::drawAll(SDL_Renderer* renderer)
{
    for (auto entity : entities) {
        // Get player-specific data
        if (entity->getType() == "player") {
            player* p = dynamic_cast<player*>(entity);
            SDL_Rect srcRect = p->getAnimationFrame();
            SDL_FRect csrcRect = { (float)srcRect.x, (float)srcRect.y, (float)srcRect.w, (float)srcRect.h };
            SDL_Texture* tex = texMgr->gettex("player_Idle");

            if (tex) {
                SDL_FRect destRect = {
                    (float)p->getX(),
                    (float)p->getY(),
                    64, 64
                };
                SDL_RenderTexture(renderer, tex, &csrcRect, &destRect);
            }
        }
    }
} 