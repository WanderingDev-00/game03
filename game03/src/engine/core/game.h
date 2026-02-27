#pragma once


#include<SDL3/SDL.h>
class game 
{
    
   private: //std::unique_ptr<IRenderer> renderer;      // Could be SDL3, OpenGL, etc.
           // std::unique_ptr<IAudioEngine> audio;      // Could be SDL_Mixer, OpenAL, etc.
           // std::unique_ptr<IPhysicsEngine> physics; 
        SDL_Window* window;
       SDL_Renderer* renderer;
     
     

    // Main methods
   public:   int logh, logw, width, height;
            bool initialize(game& state);  // Start the game
            void run();         // Game loop
            void cleanup(game& state);    // Clean up
};
