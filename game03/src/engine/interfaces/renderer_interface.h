// This is a CONTRACT.  implementing IRenderer MUST implement these methods.
class IRenderer {
public:
    virtual ~IRenderer() = default;

    // MUST implement clear() - takes a color
    virtual void clear(const Color& color) = 0;

    // MUST implement present() - show frame to screen
    virtual void present() = 0;

    // MUST implement drawSprite() - draw a sprite
    virtual void drawTexture(TextureHandle* handle, float x, float y) = 0;
};