#include "BrightFilterEffect.h"

BrightFilterEffect::BrightFilterEffect(const sf::Vector2u renderWindowSize, const std::string vertexKey, const std::string fragmentKey) :
	Effect(renderWindowSize, vertexKey, fragmentKey)
{	
	shader.setParameter("textureSampler", sf::Shader::CurrentTexture);
}

BrightFilterEffect::~BrightFilterEffect()
{
}

void BrightFilterEffect::update()
{

}

void BrightFilterEffect::draw(sf::Sprite* target)
{
	renderTexture.clear();
	renderTexture.draw(*target, &shader);

	*target = this->sprite;
}
