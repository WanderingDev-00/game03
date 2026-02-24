#include <SDL3/SDL_iostream.h>
#include <SDL3/SDL_error.h>
#include<iostream>
#include "textureloader.h"
void saveGameSDL(const std::string& filename, const void* data, size_t size) {
    if (SDL_SaveFile(filename.c_str(), data, size)) {
        std::cout << "Game saved successfully with SDL!" << std::endl;
    }
    else {
        std::cout << "Error saving game with SDL: " << SDL_GetError() << std::endl;
    }
}
void* loadGameSDL(const std::string& filename, size_t& size) {
    void* data = SDL_LoadFile(filename.c_str(), &size);
    if (data) {
        std::cout << "Game loaded successfully with SDL, size: " << size << std::endl;
    }
    else {
        std::cout << "Error loading game with SDL: " << SDL_GetError() << std::endl;
    }
    return data;
}
