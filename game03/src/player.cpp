#include "player.h"

Player::Player(float startX, float startY, SDL_Texture* tex)
    : x(startX), y(startY), texture(tex) {
}

void Player::update(float deltaTime) {
    // Basic movement to test logic
    const bool* keys = SDL_GetKeyboardState(NULL);

    if (keys[SDL_SCANCODE_W]) y -= speed * deltaTime;
    if (keys[SDL_SCANCODE_S]) y += speed * deltaTime;
    if (keys[SDL_SCANCODE_A]) x -= speed * deltaTime;
    if (keys[SDL_SCANCODE_D]) x += speed * deltaTime;
}

void Player::draw(SDL_Renderer* renderer) {
    if (texture) {
        // Since your logical size is 640x320, 
        // a 64x64 player will look a decent size.
        SDL_FRect destRect = { x, y, 64.0f, 64.0f };

        // Draw the texture we stored during construction
        SDL_RenderTexture(renderer, texture, NULL, &destRect);
    }
}