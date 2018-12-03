#include "PlayState.h"

PlayState* PlayState::instance;

PlayState::PlayState() :
	particleManager{ ParticleManager() },
	player{ Player() },
	brightFilterEffect{ new BrightFilterEffect(sf::Vector2u(1920, 1080), "DefaultVertex", "BrightFilterFragment") },
	horizontalBlurEffect{ new HorizontalBlurEffect(sf::Vector2u(1920, 1080), "HorizontalBlur", "BlurFragment") },
	verticalBlurEffect{ new VerticalBlurEffect(sf::Vector2u(1920, 1080), "VerticalBlur", "BlurFragment") },
	bloomEffect{ new BloomEffect(sf::Vector2u(1920, 1080), "DefaultVertex", "CombineFragment") },
	waveEffect{ new WaveEffect(sf::Vector2u(1920, 1080), "WaveVertex", "WaveFragment") }
{
	orginalRenderTexture.display();
	orginalRenderTexture.create(1920, 1080);
	orginalSprite.setTexture(orginalRenderTexture.getTexture());
	centerSprite(&orginalSprite);	

	orginalSaturation = 1.f;
	bloomSaturation = 5.f;

	orginalIntensity = 1.f;
	bloomIntensity = 10.f;	

	//texture = *ResourceManager::getInstance()->getTexture("whore");
	testSprite.setTexture(texture);
}

PlayState::~PlayState()
{
	delete instance;
}

void PlayState::handleEvents(sf::Event event)
{	
	player.handleEvents(event);
}

void PlayState::cleanup()
{
	particleManager.cleanup();

	delete brightFilterEffect;
	delete horizontalBlurEffect;
	delete verticalBlurEffect;
	delete bloomEffect;
	delete waveEffect;
}

void PlayState::initialize()
{

}

void PlayState::update(Game* game, sf::Time dt)
{
	dynamic_cast<HorizontalBlurEffect&>(*horizontalBlurEffect).update
	(
		std::pair<std::string, float>("textureWidth", 1920.f)
	);

	dynamic_cast<VerticalBlurEffect&>(*verticalBlurEffect).update
	(
		std::pair<std::string, float>("textureHeight", 1080.f)
	);
	
	dynamic_cast<BloomEffect&>(*bloomEffect).update
	(
		std::pair<std::string, sf::Texture>("orginalTexture", const_cast<sf::Texture&>(orginalRenderTexture.getTexture())),
		std::pair<std::string, float>("orginalSaturation", orginalSaturation),
		std::pair<std::string, float>("bloomSaturation", bloomSaturation),
		std::pair<std::string, float>("orginalIntensity", orginalIntensity),
		std::pair<std::string, float>("bloomIntensity", bloomIntensity)
	);

	dynamic_cast<WaveEffect&>(*waveEffect).update
	(
		std::pair<std::string, float>("tx", 0.3477f),
		std::pair<std::string, float>("ty", 0.7812f)
	);

	particleManager.update(game, dt);
	player.update(game, dt);
}

void PlayState::draw(Game* game)
{
	orginalRenderTexture.clear();
	orginalRenderTexture.draw(player);
	orginalRenderTexture.draw(particleManager);

	finalSprite = orginalSprite;

	brightFilterEffect->draw(&finalSprite);
	horizontalBlurEffect->draw(&finalSprite);
	verticalBlurEffect->draw(&finalSprite);
	bloomEffect->draw(&finalSprite);

	game->getWindow()->draw(finalSprite);
}