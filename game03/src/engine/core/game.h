#pragma once
#include"engine/time/time_manager.h"
#include<engine/rendering/rendering_manager.h>
#include"engine/rendering/texturemanager.h"

#include<SDL3/SDL.h>
class Gamerender;
class TextureManager;

class Game
{

private: //std::unique_ptr<IRenderer> renderer;      // Could be SDL3, OpenGL, etc.
    // std::unique_ptr<IAudioEngine> audio;      // Could be SDL_Mixer, OpenAL, etc.
    // std::unique_ptr<IPhysicsEngine> physics; 
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    int logh =320, logw=640, width=640, height=320;
    bool running = false ;
    TimeCalc& timer = TimeCalc::getInstance();
    Gamerender&  gamerender = Gamerender::getInstance();

    TextureManager& texmgr = TextureManager::getInstance();

    float deltatime = 0;

    // Private constructor - can't create instances from outside
    Game() = default;

    // Delete copy constructor and assignment operator
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete; 


    // Main methods
public:

    // Static method to get the single instance
    static Game& getInstance() {
        static Game instance;  // Created only once
        return instance;
    }
    bool initialize(SDL_Renderer* render, SDL_Window* win);  // Start the game
    void run(SDL_Renderer* Ren);        // TimeCalc loop
    void cleanup(SDL_Window* window, SDL_Renderer* renderer);
    void  getwindowsize(int Width, int Height) {width =Width ,height=Height; } // Clean up
    SDL_Renderer* getrenderer() { return renderer; }
    SDL_Window* getwindow() { return window; }
    bool getrunning() { return running; }




};