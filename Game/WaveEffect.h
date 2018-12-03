#ifndef WAVE_EFFECT_H
#define WAVE_EFFECT_H

#include "Effect.h"

class WaveEffect : public Effect
{
public:
	WaveEffect(const sf::Vector2u renderWindowSize, const std::string vertexKey, const std::string fragmentKey);
	~WaveEffect();

	void update(const std::pair<std::string, float> tx, const std::pair<std::string, float> ty);

	void draw(sf::Sprite* target) override;
};

#endif