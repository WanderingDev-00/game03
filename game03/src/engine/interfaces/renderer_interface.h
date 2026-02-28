// This is a CONTRACT.  implementing IRenderer MUST implement these methods.
#include<SDL3/SDL.h>


// src/engine/interfaces/renderer_interface.h
class IRenderer {
public:
    virtual ~IRenderer() = default;
    virtual void drawSprite() = 0;
    virtual void clear() = 0;
    // ... all rendering methods
};

// Same for Audio, Physics, Save