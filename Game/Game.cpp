#include "Game.h"

Game::Game() :
	window{ new sf::RenderWindow{ sf::VideoMode{WINDOW_WIDTH, WINDOW_HEIGHT}, "Game", sf::Style::Default } }
{
	sf::View view;
	view.setSize(WINDOW_WIDTH, -WINDOW_HEIGHT);
	view.setCenter(static_cast<sf::Vector2f>(window->getSize()) * 0.5f);
	window->setView(view);
	//window->setKeyRepeatEnabled(true);

	window->setFramerateLimit(120);

	//window->setVerticalSyncEnabled(true);
}

Game::~Game()
{
	delete window;
}

void Game::initialize()
{
	running = true;
	paused = false;

	std::srand(static_cast<unsigned int>(time(NULL)));
}

void Game::cleanup()
{
	while (!gameStates.empty())
	{
		gameStates.back()->cleanup();
		gameStates.pop_back();
	}
	window->close();

	ResourceManager::getInstance()->cleanup();
}

void Game::handleEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			running = false;
		}
	}

	if (!gameStates.empty())
	{
		gameStates.back()->handleEvents(event);
	}
}

void Game::update()
{
	if (!gameStates.empty())
	{
		sf::Time time = clock.restart();
		gameStates.back()->update(this, time);
	}
}

void Game::draw()
{
	window->clear();
	if (!gameStates.empty())
	{
		gameStates.back()->draw(this);
	}
	window->display();
}

void Game::pushState(GameState* gameState)
{
	gameStates.push_back(gameState);
	gameStates.back()->initialize();
}

void Game::popState() 
{
	if (!gameStates.empty())
	{
		gameStates.back()->cleanup();
		gameStates.pop_back();
	}
}

void Game::changeState(GameState* gameState)
{
	popState();
	pushState(gameState);
}
