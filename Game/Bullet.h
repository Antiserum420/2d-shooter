#ifndef BULLET_H
#define BULLET_H

#include "SFML\Graphics.hpp"
#include "Game.h"
#include <vector>
#include "ResourceManager.h"
#include "Utility.h"

class Bullet : public sf::Drawable
{
private:
	bool alive;
	
	sf::Sprite bulletSprite;

	std::string textureName;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f scale;
	sf::Color color;
	float angle;

public:
	Bullet(std::string textureName, sf::Vector2f position, sf::Vector2f velocity, float angle, sf::Color color);
	~Bullet();

	void update(Game* game, sf::Time dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	bool isAlive()
	{
		return alive;
	}
};

#endif // !BULLET_H