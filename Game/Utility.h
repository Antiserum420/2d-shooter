#ifndef UTILITY_H
#define UTILITY_H

#include "SFML\Graphics\Sprite.hpp"
#include "SFML\Graphics\Color.hpp"
#include "SFML/System/Vector2.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

inline sf::Color convertHSVToRGB(const float h, const float s, const float v)
{
	float r, g, b;
	int i = static_cast<sf::Uint32>(std::floor(h * 6.f));
	float f = h * 6 - i;
	float p = v * (1 - s);
	float q = v * (1 - f * s);
	float t = v * (1 - (1 - f) * s);

	switch (i % 6)
	{
	case 0: r = v, g = t, b = p; break;
	case 1: r = q, g = v, b = p; break;
	case 2: r = p, g = v, b = t; break;
	case 3: r = p, g = q, b = v; break;
	case 4: r = t, g = p, b = v; break;
	case 5: r = v, g = p, b = q; break;
	}
	return sf::Color(sf::Uint8(r * 255.f), sf::Uint8(g * 255.f), sf::Uint8(b * 255.f));
}

inline float linearInterpolate(const float a, const float b, const float t)
{
	return (1.f - t) * a + t * b;
}

inline sf::Color linearInterpolate(const sf::Color a, const sf::Color b, const float t)
{
	return sf::Color
	(
		sf::Uint8(linearInterpolate(a.r, b.r, t)),
		sf::Uint8(linearInterpolate(a.g, b.g, t)),
		sf::Uint8(linearInterpolate(a.b, b.b, t)),
		sf::Uint8(linearInterpolate(a.a, b.a, t))
	);
}

inline float fRand(const float minVal, const float maxVal)
{
	float f = static_cast<float>(rand()) / RAND_MAX;
	return minVal + f * (maxVal - minVal);
}

inline sf::Vector2f angleToVector(const float angle)
{
	return sf::Vector2f
	(
		std::cos(angle * static_cast<float>(M_PI) / 180.f),
		std::sin(angle * static_cast<float>(M_PI) / 180.f)
	);
}

inline float vectorToAngle(const sf::Vector2f vector)
{
	return std::atan2(vector.y, vector.x) * 180.f / static_cast<float>(M_PI); 
}

inline void centerSprite(sf::Sprite* sprite)
{
	sf::FloatRect bounds = sprite->getLocalBounds();
	sprite->setOrigin(std::floor(bounds.left + bounds.width * 0.5f), std::floor(bounds.top + bounds.height * 0.5f));
}

#endif
