#pragma once
#include "entity.h"

class Player : public Entity {
public:
    // We store the texture pointer we got from the manager
    Player(float startX, float startY, SDL_Texture* tex);

    // We MUST implement all of these to stop the "Abstract Class" error
    void update(float deltaTime) override;
    void draw(SDL_Renderer* renderer) override;

    float getX() const override { return x; }
    float getY() const override { return y; }
    std::string getType() const override { return "Player"; }

private:
    float x, y;
    float speed = 200.0f;
    SDL_Texture* texture; // The pointer from our TextureManager
};