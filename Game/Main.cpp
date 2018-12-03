#include "Game.h"
#include "PlayState.h"

int main() {

	Game game;
	game.initialize();

	game.pushState(PlayState::getInstance());

	while (game.isRunning())
	{
		game.handleEvents();

		if (!game.isPaused())
		{
			game.update();
			game.draw();			
		}
	}
	game.cleanup();

	return 0;
}