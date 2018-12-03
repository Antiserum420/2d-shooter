#include "ParticleManager.h"

ParticleManager::ParticleManager()
{

}

ParticleManager::~ParticleManager()
{

}

void ParticleManager::cleanup()
{
	while (!particles.empty())
	{
		delete particles.back();
		particles.pop_back();		
	}
}

void ParticleManager::update(Game* game, sf::Time dt)
{
	std::vector<Particle*>::iterator particle;
	for (particle = particles.begin(); particle != particles.end();)
	{
		if (!(*particle)->isAlive())
		{
			delete *particle;
			particle = particles.erase(particle);
		}
		else
		{		
			(*particle)->update(game, dt);
			++particle;						
		}
	}
}

void ParticleManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for each(auto particle in particles)
	{
		target.draw(*particle, states);
	}	
}

void ParticleManager::spawnParticles(sf::Vector2f position)
{
	float hue1 = fRand(0.f, 6.f);
	float hue2 = fRand(0.f, 6.f);

	sf::Color colorA = convertHSVToRGB(hue1, 0.5f, 1.f);
	sf::Color colorB = convertHSVToRGB(hue2, 0.5f, 1.f);
	sf::Color color = linearInterpolate(colorA, colorB, 1.f);

	for (int i = 0; i < 120; ++i)
	{
		float angle = fRand(0, 360);
		float speed = fRand(800, 2000);
		float friction = 0.02f;

		Particle* particle = new Particle("laser", position, sf::Vector2f(speed, speed), color, friction, angle, sf::seconds(2.5f));
		particles.push_back(particle);
	}	
}

void ParticleManager::makeExaustFire(sf::Vector2f position, float angle)
{
	float hue1 = 6.f;
	float hue2 = 6.f;

	sf::Color colorA = convertHSVToRGB(hue1, 0.5f, 1.f);
	sf::Color colorB = convertHSVToRGB(hue2, 0.5f, 1.f);
	sf::Color color = linearInterpolate(colorA, colorB, 1.f);

	for (int i = 0; i < 1; ++i)
	{
		float speed = fRand(800, 2000);
		float friction = 0.02f;

		Particle* particle = new Particle("laser", position, sf::Vector2f(speed, speed), color, friction, angle, sf::seconds(2.5f));
		particles.push_back(particle);
	}
}

