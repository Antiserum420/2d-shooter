#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include "SFML\Graphics\Texture.hpp"
#include "SFML\Graphics\Shader.hpp"
#include <exception>

class ResourceManager
{
private:
	ResourceManager();
	static ResourceManager* instance;

	std::map<std::string, sf::Texture*> textures;

public:	
	~ResourceManager();

	static ResourceManager* getInstance()
	{
		if (!instance)
		{
			instance = new ResourceManager();
		}
		return instance;
	}

	void cleanup();
	sf::Texture* getTexture(const std::string key);
};
#endif
