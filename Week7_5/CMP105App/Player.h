#pragma once
#include "Companion.h"
#include "Framework/GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void handleInput(float dt) override;
	void update(float dt) override;
	Companion* getCompanion()
	{
		return &companion;
	};

private:
	Companion companion;
};