#include "WaveEffect.h"

WaveEffect::WaveEffect(const sf::Vector2u renderWindowSize, const std::string vertexKey, const std::string fragmentKey) :
	Effect(renderWindowSize, vertexKey, fragmentKey)
{
	shader.setUniform("textureSampler", sf::Shader::CurrentTexture);
}


WaveEffect::~WaveEffect()
{
}

void WaveEffect::update(const std::pair<std::string, float> tx, const std::pair<std::string, float> ty)
{
	shader.setParameter(tx.first, tx.second);
	shader.setParameter(ty.first, ty.second);
}

void WaveEffect::draw(sf::Sprite* target)
{
	renderTexture.clear();
	renderTexture.draw(*target, &shader);

	*target = sprite;
}
