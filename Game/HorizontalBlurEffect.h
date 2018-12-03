#ifndef HORIZONTAL_BLUR_EFFECT_H
#define HORIZONTAL_BLUR_EFFECT_H

#include "Effect.h"
#include "SFML\Graphics\Sprite.hpp"

class HorizontalBlurEffect : public Effect
{
public:
	HorizontalBlurEffect(const sf::Vector2u renderWindowSize, const std::string vertexKey, const std::string fragmentKey);
	~HorizontalBlurEffect();

	void update(const std::pair<std::string, float> textureWidth);
	void draw(sf::Sprite* target) override;
};

#endif // !HORIZONTAL_BLUR_EFFECT_H