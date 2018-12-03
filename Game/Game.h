#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "GameState.h"
#include "ResourceManager.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

class GameState;

class Game
{

public:
	Game();
	~Game();	

private:
	sf::RenderWindow* window;
	std::vector<GameState*> gameStates;
	bool running, paused;
	sf::Clock clock;

public:
	void initialize();
	void handleEvents();
	void update();
	void draw();
	void cleanup();
	
	void pushState(GameState* gameState);
	void popState();
	void changeState(GameState* gameState);

	bool isRunning() 
	{
		return running;
	};
	bool isPaused()
	{
		return paused;
	};	

	sf::RenderWindow* getWindow()
	{
		return window;
	}
};
#endif // !GAME_H
