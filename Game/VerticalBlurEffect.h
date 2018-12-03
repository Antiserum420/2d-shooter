#ifndef VERTICAL_BLUR_EFFECT_H
#define VERTICAL_BLUR_EFFECT_H

#include "Effect.h"

class VerticalBlurEffect : public Effect
{
public:
	VerticalBlurEffect(const sf::Vector2u renderWindowSize, const std::string vertexKey, const std::string fragmentKey);
	~VerticalBlurEffect();

	void update(const std::pair<std::string, float> textureHeight);

	void draw(sf::Sprite* sprite) override;
};

#endif // !VERTICAL_BLUR_EFFECT