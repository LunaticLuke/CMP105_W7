#include "Player.h"
#include <Windows.h>

Player::Player()
{
	setPosition(200, 200);
	setSize(sf::Vector2f(100, 100));
	bullet = &bulletObjects[0];
	bullet->speed = 1;
	bullet = &bulletObjects[1];
	bullet->speed = 0.9;
	bullet = &bulletObjects[2];
	bullet->speed = 0.8;
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
		for (int i = 0; i < 3; i++)
		{
			

			bullet = &bulletObjects[i];
			bullet->setPosition(getPosition() + sf::Vector2f(getSize().x / 2, getSize().y / 2));

		}
	}
}

void Player::update(float dt) 
{
	bulletObjects[0].update(dt);
	bulletObjects[1].update(dt);
	bulletObjects[2].update(dt);
}