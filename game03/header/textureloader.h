#pragma once
#include "texturemanager.h"
#include"gamerender.h"
class TextureManager;

class loadAreatex
{
private: float area, cameraregion;
	   player play;
	   TextureManager texMgr ;
public:
	void loadAreaTexture(SDL_Renderer* renderer);
	void loadDecide(); 
		void playerLoadout(SDL_Renderer* renderer);

  
};