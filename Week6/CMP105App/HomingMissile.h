#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class HomingMissile : 
	public GameObject
{
public:
	HomingMissile();
	~HomingMissile();
	void update(float dt) override;
	void setTarget(sf::Vector2f trgt);

	float speed;

protected:
	sf::Vector2f target;
};

