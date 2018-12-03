#include "VerticalBlurEffect.h"

VerticalBlurEffect::VerticalBlurEffect(const sf::Vector2u renderWindowSize, const std::string vertexKey, const std::string fragmentKey) :
	Effect(renderWindowSize, vertexKey, fragmentKey)
{
	shader.setUniform("textureSampler", sf::Shader::CurrentTexture);	
}


VerticalBlurEffect::~VerticalBlurEffect()
{
}

void VerticalBlurEffect::update(const std::pair<std::string, float> textureHeight)
{
	shader.setParameter(textureHeight.first, textureHeight.second);
}

void VerticalBlurEffect::draw(sf::Sprite* target)
{
	renderTexture.clear();
	renderTexture.draw(*target, &shader);

	*target = this->sprite;
}