#include "Bullet.h"

Bullet::Bullet(std::string textureName, sf::Vector2f position, sf::Vector2f velocity, float angle, sf::Color color) :
	textureName { textureName },
	position { position },
	velocity { velocity },
	angle { angle },
	color { color }
{
	alive = true;

	bulletSprite.setTexture(*ResourceManager::getInstance()->getTexture(textureName));
	bulletSprite.setPosition(position);
	bulletSprite.setRotation(angle);
	bulletSprite.setColor(color);
	//sf::FloatRect bounds = bulletSprite.getLocalBounds();
}


Bullet::~Bullet()
{
}

void Bullet::update(Game* game, sf::Time dt)
{
	if (position.x > game->getWindow()->getSize().x || position.y > game->getWindow()->getSize().y ||
		position.x < 0.f || position.y < 0.f)
	{
		alive = false;
		return;
	}

	sf::Vector2f direction = angleToVector(angle);

	//velocity *= std::pow(friction, dt.asSeconds());

	position.x += velocity.x * direction.x * dt.asSeconds();
	position.y += velocity.y * direction.y * dt.asSeconds();

	bulletSprite.setPosition(position);
	bulletSprite.setPosition(position);
}
void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(bulletSprite, states);
}