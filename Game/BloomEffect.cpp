#include "BloomEffect.h"

BloomEffect::BloomEffect(const sf::Vector2u renderWindowSize, const std::string vertexKey, const std::string fragmentKey) :
	Effect(renderWindowSize, vertexKey, fragmentKey)
{
	shader.setUniform("bloomTexture", sf::Shader::CurrentTexture);
}


BloomEffect::~BloomEffect()
{
}

void BloomEffect::update
(
	std::pair<std::string, sf::Texture> orignalTexture,
	std::pair<std::string, float> orginalSaturation,
	std::pair<std::string, float> bloomSaturation,
	std::pair<std::string, float> orginalIntensity,
	std::pair<std::string, float> bloomIntensity
)
{
	shader.setParameter(orignalTexture.first, orignalTexture.second);
	shader.setParameter(orginalSaturation.first, orginalSaturation.second);
	shader.setParameter(bloomSaturation.first, bloomSaturation.second);
	shader.setParameter(orginalIntensity.first, orginalIntensity.second);
	shader.setParameter(bloomIntensity.first, bloomIntensity.second);
}

void BloomEffect::draw(sf::Sprite* target)
{
	renderTexture.clear();
	renderTexture.draw(*target, &shader);

	*target = this->sprite;
}
