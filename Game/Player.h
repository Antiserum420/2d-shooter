#ifndef PLAYER_H
#define PLAYER_H

#include "SFML\Graphics.hpp"
#include "Game.h"
#include "ResourceManager.h"
#include "Utility.h"
#include "Constants.h"
#include "ParticleManager.h"
#include "Bullet.h"

class Player : public sf::Drawable
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2f leftStick;
	sf::Vector2f rightStick;

	bool rightTrigger;

	sf::Vector2f position;
	sf::Vector2f velocity;
	float friction;

	ParticleManager particleManager;

	std::vector<Bullet*> bullets;
	sf::Time timeLeft;

	const float BULLET_COOLDOWN = 1.f;

public:
	Player();
	~Player();

	void cleanup();
	void handleEvents(sf::Event event);
	void update(Game* game, sf::Time dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif