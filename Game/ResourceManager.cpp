#include "ResourceManager.h"

ResourceManager* ResourceManager::instance;

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::cleanup()
{
	for each(auto texture in textures)
	{
		delete texture.second;
	}
}

sf::Texture* ResourceManager::getTexture(const std::string key)
{
	if (textures.count(key) == 1)
	{
		return textures.at(key);
	}
	else
	{
		sf::Texture* texture = new sf::Texture();

		if (!texture->loadFromFile("textures/" + key + ".png"))
		{
			throw new std::runtime_error("Could not load texture with key " + key);
		}
		textures.insert({ key, texture });
		return textures.at(key);
	}
}
