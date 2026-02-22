
#include "texturemanager.h"


SDL_Texture* TextureManager::Load(SDL_Renderer* renderer, const std::string& id, const std::string& filepath)
{
	auto entry = texturemap.find(id);
	if (entry != texturemap.end())
	{
		entry->second.refcount++;
		return entry->second.tex;//Go to the value part of this map entry and return the tex field found inside it

	}
	SDL_Texture* newtex = IMG_LoadTexture(renderer, filepath.c_str());
	if (!newtex)
	{
		SDL_Log("Failed to load %s: %s", filepath.c_str(), SDL_GetError());
		return nullptr;

	}
	texturemap[id] = { newtex,1 };
	return newtex;
}
void TextureManager::unload(const std::string& id)
{
	auto entry = texturemap.find(id);
	if (entry != texturemap.end())
	{
		entry->second.refcount--;
		
		if (entry->second.refcount <= 0)
		{
			
			SDL_DestroyTexture(entry->second.tex);
				texturemap.erase(entry);
		}
	}

	
}
void TextureManager::ALLTexclear()
{
	for (auto& [id, resource] : texturemap)
	{
		SDL_DestroyTexture(resource.tex);//destroys the texture from map all of it 
	}
	texturemap.clear();
	SDL_Log("all texture cleared");
}
SDL_Texture* TextureManager::gettex(const std::string& id)
{
	auto it = texturemap.find(id);
	return (it != texturemap.end()) ? it->second.tex : nullptr;
}



