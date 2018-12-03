#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "GameState.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "ParticleManager.h"
#include "ResourceManager.h"
#include "Player.h"
#include "BrightFilterEffect.h"
#include "HorizontalBlurEffect.h"
#include "VerticalBlurEffect.h"
#include "BloomEffect.h"
#include "WaveEffect.h"

class PlayState : public GameState
{
private:
	static PlayState* instance;

	sf::Sprite orginalSprite, finalSprite;

	sf::RenderTexture orginalRenderTexture;

	ParticleManager particleManager;

	Player player;

	Effect* brightFilterEffect, *horizontalBlurEffect, *verticalBlurEffect, *bloomEffect, *waveEffect;

	sf::Texture texture;
	sf::Sprite testSprite;

	float orginalSaturation, bloomSaturation;
	float orginalIntensity, bloomIntensity;

protected:
	PlayState();
	

public:
	~PlayState();

	static PlayState* getInstance()
	{
		if (!instance)
		{
			instance = new PlayState();
		}
		return instance;
	}

	void cleanup() override;

	void initialize() override;

	void handleEvents(sf::Event event) override;

	void update(Game* game, sf::Time dt) override;

	void draw(Game* Game) override;
};
#endif // !PLAYSTATE_H