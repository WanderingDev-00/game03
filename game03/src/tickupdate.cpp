#include "tickupdate.h"
#include "gamerender.h"

//  MASTER UPDATE: Called once per frame from main
void update(Gamerender& render, float deltatime)
{
    updateEntities(render, deltatime);  // Update player, enemies, etc
    updateMap(deltatime);                // Update map stuff
    updateCamera(deltatime);             // Update camera
}

//  NEW: Update all entities (replaces old updateplayer)
void updateEntities(Gamerender& render, float deltatime)
{
    render.updateAll(deltatime);  // Calls player::update(), enemy::update(), etc
}

//  KEEP: These stay the same
void updateMap(float deltatime)
{
    // Map logic here
}

void updateCamera(float deltatime)
{
    // Camera logic here
}