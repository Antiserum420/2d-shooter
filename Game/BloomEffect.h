#ifndef BLOOM_EFFECT_H
#define BLOOM_EFFECT_H

#include "Effect.h"
#include "SFML\Graphics\Sprite.hpp"

class BloomEffect : public Effect
{
public:
	BloomEffect(const sf::Vector2u renderWindowSize, const std::string vertexKey, const std::string fragmentKey);
	~BloomEffect();

	void update
	(
		std::pair<std::string, sf::Texture> orignalTexture,
		std::pair<std::string, float> orginalSaturation,
		std::pair<std::string, float> bloomSaturation,
		std::pair<std::string, float> orginalIntensity,
		std::pair<std::string, float> bloomIntensity
	);

	void draw(sf::Sprite* target) override;
};

#endif // !BLOOM_EFFECT_H