#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "SFML\Graphics.hpp"
#include "Game.h"

class Game;

class GameState
{
public:
	~GameState()
	{

	}

	virtual void cleanup() = 0;

	virtual void initialize() = 0;

	virtual void handleEvents(sf::Event event) = 0;

	virtual void update(Game* game, sf::Time dt) = 0;

	virtual void draw(Game* game) = 0;

protected:
	GameState()
	{

	}	
};
#endif // !GameState

