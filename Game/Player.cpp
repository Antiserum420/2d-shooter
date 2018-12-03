#include "Player.h"

Player::Player()
{
	texture = *ResourceManager::getInstance()->getTexture("player");
	sprite.setTexture(texture);
	centerSprite(&sprite);
	position = sf::Vector2f(1920 * 0.5f, 1080 * 0.5f);
	sprite.setPosition(position);

	if (sf::Joystick::isConnected(0))
	{
		std::cout << "controller 1 connected";
	}
		
	friction = 1.f;
	velocity = sf::Vector2f(200.f, 200.f);

	rightTrigger = false;
}

Player::~Player()
{

}

void Player::cleanup()
{

}

void Player::handleEvents(sf::Event event)
{
	if (event.type == sf::Event::JoystickMoved)
	{	
		leftStick.x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		leftStick.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

		rightStick.x = sf::Joystick::getAxisPosition(0, sf::Joystick::U);
		rightStick.y = sf::Joystick::getAxisPosition(0, sf::Joystick::R);	

		rightTrigger = sf::Joystick::getAxisPosition(0, sf::Joystick::Z) < -0.5f;
	}
}

void Player::update(Game* game, sf::Time dt)
{
	timeLeft -= dt;

	particleManager.update(game, dt);

	std::vector<Bullet*>::iterator bullet;
	for (bullet = bullets.begin(); bullet != bullets.end();)
	{
		if (!(*bullet)->isAlive())
		{
			delete *bullet;
			bullet = bullets.erase(bullet);
		}
		else
		{
			(*bullet)->update(game, dt);
			++bullet;
		}
	}

	if (std::abs(leftStick.x) < CONTROLLER_DEADZONE)
	{
		leftStick.x = 0.f;
	}
	if (std::abs(leftStick.y) < CONTROLLER_DEADZONE)
	{
		leftStick.y = 0.f;
	}
	if (std::abs(rightStick.x) < CONTROLLER_DEADZONE)
	{
		rightStick.x = 0.f;
	}
	if (std::abs(rightStick.y) < CONTROLLER_DEADZONE)
	{
		rightStick.y = 0.f;
	}

	if ((std::abs(leftStick.x) > CONTROLLER_MOVEMENT_THRESHOLD || std::abs(leftStick.y) > CONTROLLER_MOVEMENT_THRESHOLD))
	{
		float angle = vectorToAngle(leftStick);
		sprite.setRotation(angle);

		sf::Vector2f direction = angleToVector(angle);

		velocity *= std::pow(friction, dt.asSeconds());

		position.x += velocity.x * direction.x * dt.asSeconds();
		position.y += velocity.y * direction.y * dt.asSeconds();

		sprite.setPosition(position);		
		//particleManager.makeExaustFire(position, angle + 180.f);
	}	

	if (rightTrigger && timeLeft <= sf::seconds(0.f))
	{
		float hue1 = fRand(0.f, 6.f);
		float hue2 = fRand(0.f, 6.f);

		sf::Color colorA = convertHSVToRGB(hue1, 0.5f, 1.f);
		sf::Color colorB = convertHSVToRGB(hue2, 0.5f, 1.f);
		sf::Color color = linearInterpolate(colorA, colorB, 1.f);


		Bullet* bullet = new Bullet("laser", position, sf::Vector2f(300, 300), sprite.getRotation(), color);
		bullets.push_back(bullet);

		//sf::Vector2f rightBulletPosition = rotation.transformPoint(-10, 0.f);

		timeLeft = sf::seconds(BULLET_COOLDOWN);
	}
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
	target.draw(particleManager, states);
	
	for each (auto bullet in bullets)
	{
		target.draw(*bullet, states);
	}
}
