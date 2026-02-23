#pragma once
class Gamerender;  // Forward declare

//MAIN: This is what main loop calls
void update(Gamerender& render, float deltatime);

//  HELPERS: Called by update()
void updateEntities(Gamerender& render, float deltatime);
void updateMap(float deltatime);
void updateCamera(float deltatime);