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
    SDL_Window* window;
    SDL_Renderer* renderer;
    int logh =320, logw=640, width, height;
    bool running ;
    TimeCalc& timer = TimeCalc::getInstance();
    Gamerender&  gamerender = Gamerender::getInstance();

    TextureManager& texmgr = TextureManager::getInstance();

    float deltatime;

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
    bool initialize();  // Start the game
    void run();         // TimeCalc loop
    void cleanup(SDL_Window* window, SDL_Renderer* renderer);
    void  getwindowsize(int Width, int Height) {width =Width ,height=Height; } // Clean up
   
    bool getrunning() { return running; }




};