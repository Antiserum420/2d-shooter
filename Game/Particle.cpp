#include "Particle.h"

Particle::Particle(std::string textureName, sf::Vector2f position, sf::Vector2f velocity, sf::Color color, float friction, float angle, sf::Time lifeTime) :
	textureName{ textureName },
	position{ position },
	velocity{ velocity },
	color{ color },	
	friction{ friction },
	angle{ angle },
	lifeTime{ lifeTime }
{
	alive = true;

	sprite.setTexture(*ResourceManager::getInstance()->getTexture(textureName));
	sprite.setColor(color);
	sprite.setPosition(position);
	sprite.setRotation(angle);
	
	scale = sprite.getScale();

	timeLeft = lifeTime;
}

Particle::~Particle()
{

}

void Particle::update(Game* game, sf::Time dt)
{	
	timeLeft -= dt;

	if (timeLeft <= sf::seconds(0.f))
	{
		alive = false;
		return;
	}

	sf::Vector2f direction = angleToVector(angle);

	velocity *= std::pow(friction, dt.asSeconds()); 

	position.x += velocity.x * direction.x * dt.asSeconds();
	position.y += velocity.y * direction.y * dt.asSeconds();

	sprite.setPosition(position);	

	sf::Color endColor = sf::Color(color.r, color.g, color.b, 0);	
	sf::Color currentColor = linearInterpolate(endColor, color, timeLeft / lifeTime);
	sprite.setColor(currentColor);
	
	float currentScale = linearInterpolate(0.0f, scale.x, timeLeft / lifeTime);
	sprite.setScale(sf::Vector2f(currentScale, scale.y));	
}

void Particle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}
