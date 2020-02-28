#pragma once

#include "Framework/GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet();
	~Bullet();
	float speed = 5;
	void update(float dt);

};