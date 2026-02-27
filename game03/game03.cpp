

#include"src/engine/core/game.h"
int main(int argc, char* argv[])
{

	game state;

	if (!state.initialize(state))
	{
		return -1;
	}


	state.cleanup(state);
	return 0;

}