#pragma once
#include"src/engine/time/time_manager.h"


#include<SDL3/SDL.h>


class Game
{

private: //std::unique_ptr<IRenderer> renderer;      // Could be SDL3, OpenGL, etc.
    // std::unique_ptr<IAudioEngine> audio;      // Could be SDL_Mixer, OpenAL, etc.
    // std::unique_ptr<IPhysicsEngine> physics; 
    SDL_Window* window;
    SDL_Renderer* renderer;
    int logh, logw, width, height;
    bool running;
    TimeCalc& timer = TimeCalc::getInstance();

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
    bool initialize(SDL_Window* window, SDL_Renderer* renderer);  // Start the game
    void run();         // TimeCalc loop
    void cleanup(SDL_Window* window, SDL_Renderer* renderer);
    int  getwindowsize(int width, int height) { return width, height; } // Clean up
    int  getwindowsize(int width, int height) { return width, height; }
    bool getrunning() { return running; }




};