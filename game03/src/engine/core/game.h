#pragma once


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
     
     

    // Main methods
   public:   
            bool initialize(SDL_Window* window ,SDL_Renderer* renderer);  // Start the game
            void run();         // Game loop
            void cleanup(SDL_Window* window, SDL_Renderer* renderer);
            int  getwindowsize(int width , int height) { return width,  height; } // Clean up
};
