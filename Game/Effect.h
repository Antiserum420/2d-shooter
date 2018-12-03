#ifndef EFFECT_H
#define EFFECT_H

#include "SFML\Graphics\Shader.hpp"
#include "SFML\Graphics\RenderTexture.hpp"
#include "SFML\Graphics\Sprite.hpp"
#include "ResourceManager.h"

class Effect
{
protected:
	Effect(const sf::Vector2u renderWindowSize, const std::string vertexKey, const std::string fragmentKey)
	{
		renderTexture.display();
		renderTexture.create(renderWindowSize.x, renderWindowSize.y);
		sprite.setTexture(renderTexture.getTexture());
		sprite.setOrigin(sf::Vector2f(1.f, 1.f));

		if (!sf::Shader::isAvailable())
		{
			throw new std::runtime_error("shader not available");
		}
		else if (!shader.loadFromFile("shaders/" + vertexKey + ".vs", "shaders/" + fragmentKey + ".fs"))
		{
			throw new std::runtime_error("Could not load shader with vertexKey " + vertexKey + " and fragmentKey " + fragmentKey);
		}
	}

	sf::Shader shader;
	sf::RenderTexture renderTexture;
	sf::Sprite sprite;

public:	
	~Effect()
	{

	}

	virtual void draw(sf::Sprite* target) = 0;
};

#endif // !EFFECT_H
