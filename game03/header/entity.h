#pragma once
#include <SDL3/SDL.h>
#include <string>

class Entity {
public:
    // Virtual destructor is vital so Player memory is cleaned up correctly
    virtual ~Entity() {}

    // 1. Logic Update
    // We pass deltaTime so movement is smooth regardless of FPS
    virtual void update(float deltaTime) = 0;

    // 2. Simple Render
    // We only pass the renderer. No camera, no manager for now.
    virtual void draw(SDL_Renderer* renderer) = 0;

    // 3. Position Getters (Useful for logic later)
    virtual float getX() const = 0;
    virtual float getY() const = 0;

    // 4. Type Check
    virtual std::string getType() const = 0;
};