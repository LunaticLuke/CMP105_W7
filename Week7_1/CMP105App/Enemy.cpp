#include "Enemy.h"

#define THRESHOLD 5

Enemy::Enemy()
{
	setPosition(500, 500);
	setSize(sf::Vector2f(25, 25));
	setFillColor(sf::Color::Red);
	elapsedTime = 0.0f;
}


Enemy::~Enemy()
{
}

void Enemy::update(float dt)
{
	elapsedTime += dt;
	if (elapsedTime > THRESHOLD)
	{
		elapsedTime = 0.f;
		int x = rand() % 600;
		int y = rand() % 400;
		setPosition((float)x, (float)y);
	}
}
