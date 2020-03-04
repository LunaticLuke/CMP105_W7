#include "Player.h"
#include <Windows.h>

Player::Player()
{
	setPosition(200, 200);
	setSize(sf::Vector2f(100, 100));
	hasFired = false;
	bullet = &bulletObject;
}


Player::~Player()
{
}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		input->setKeyUp(sf::Keyboard::Space);
		int x = rand() % 600;
		int y = rand() % 400;
		setPosition((float)x, (float)y);
	}

	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		if (!hasFired)
		{
			bulletObject = spawn(getPosition() + sf::Vector2f(getSize().x / 2, getSize().y / 2));
			*bullet = bulletObject;
			hasFired = true;
			
		}
	}
	if (input->isKeyDown(sf::Keyboard::R))
	{
		Sleep(3);
		hasFired = false;
	}
}

void Player::update(float dt) 
{
	if (hasFired)
	{
		bullet->update(dt);
	}
}

Bullet Player::spawn(sf::Vector2f pos)
{
	Bullet newBullet;
	newBullet.setPosition(pos);
	return newBullet;
}