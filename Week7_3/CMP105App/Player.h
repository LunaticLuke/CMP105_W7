#pragma once

#include "Framework/GameObject.h"
#include "Bullet.h"


class Player : public GameObject
{
public:
	Player();
	~Player();

	void handleInput(float dt);
	void update(float dt);
	Bullet* getBullet(int bulletToGet) {
		bulletToDraw = &bulletObjects[bulletToGet];
		return bullet;
	};

private:
	Bullet bulletObjects[3];
	Bullet* bullet;
	Bullet* bulletToDraw;
	int currentBullet;
};