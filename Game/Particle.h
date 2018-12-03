#ifndef PARTICLE_H
#define PARTICLE_H

#include "SFML\Graphics.hpp"
#include "Game.h"
#include "Utility.h"

class Particle : public sf::Drawable
{
private:
	sf::Sprite sprite;

	std::string textureName;
	sf::Vector2f position;
	sf::Vector2f velocity;	
	sf::Vector2f scale;

	sf::Color color;	

	float friction;	
	float angle;	

	sf::Time lifeTime;
	sf::Time timeLeft;

	bool alive;

public:
	Particle(std::string textureName, sf::Vector2f position, sf::Vector2f velocity, sf::Color color, float friction, float angle, sf::Time lifeTime);
	~Particle();

	void update(Game* game, sf::Time dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	bool isAlive()
	{
		return alive;
	}
};
#endif
