#include "tickupdate.h"
#include "player.h"
// The Master Update Function
void update(player& play, float deltatime)
{
    // NO 'void' here! Just the names to make them RUN.
    updateplayer(play, deltatime);
    updatemap(play, deltatime);
    updatecamera(play, deltatime);
}