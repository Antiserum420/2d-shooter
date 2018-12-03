#include "HorizontalBlurEffect.h"

HorizontalBlurEffect::HorizontalBlurEffect(const sf::Vector2u renderWindowSize, const std::string vertexKey, const std::string fragmentKey) :
	Effect(renderWindowSize, vertexKey, fragmentKey)
{
	shader.setUniform("textureSampler", sf::Shader::CurrentTexture);
}

HorizontalBlurEffect::~HorizontalBlurEffect()
{
}

void HorizontalBlurEffect::update(const std::pair<std::string, float> textureWidth)
{	
	shader.setParameter(textureWidth.first, textureWidth.second);
}

void HorizontalBlurEffect::draw(sf::Sprite* target)
{
	renderTexture.clear();
	renderTexture.draw(*target, &shader);

	*target = this->sprite;
}