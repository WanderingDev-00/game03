#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <unordered_map>
#include <string>
struct TextureResource {
    SDL_Texture* tex = nullptr;
    int refcount = 0;
};

class TextureManager
{
private:std::unordered_map<std::string, TextureResource> texturemap;
       // Private constructor - can't create instances from outside
       TextureManager() = default;

       // Delete copy constructor and assignment operator
       TextureManager(const TextureManager&) = delete;
       TextureManager& operator=(const TextureManager&) = delete;

public:
    static  TextureManager& getInstance() {
    static  TextureManager instance;  // Created only once
    return instance;
}
    
    
    SDL_Texture* Load(SDL_Renderer* renderer, const std::string& id, const std::string& filepath);
      void unload(const std::string& id);
      void ALLTexclear();
      SDL_Texture* gettex(const std::string& id);

}; 