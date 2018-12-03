#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include <iostream>
#include "Particle.h"
#include "SFML\Graphics.hpp"
#include "Game.h"
#include "Utility.h"
#include "ResourceManager.h"

class Particle;

class ParticleManager : public sf::Drawable
{
private:
	std::vector<Particle*> particles;

public:
	ParticleManager();
	~ParticleManager();

	void cleanup();
	void update(Game* game, sf::Time dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void spawnParticles(sf::Vector2f position);

	void makeExaustFire(sf::Vector2f position, float angle);
};
#endif // !PARTICLE_SYSTEM_H