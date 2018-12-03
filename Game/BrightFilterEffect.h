#ifndef BRIGHT_FILTER_EFFECT_H
#define BRIGHT_FILTER_EFFECT_H

#include "Effect.h"
#include "SFML\Graphics\Sprite.hpp"

class BrightFilterEffect : public Effect
{
public:

public:
	BrightFilterEffect(const sf::Vector2u renderWindowSize, const std::string vertexKey, const std::string fragmentKey);
	~BrightFilterEffect();

	void update();

	void draw(sf::Sprite* target) override;
};

#endif // !BRIGHT_FILTER_EFFECT_H
