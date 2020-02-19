#pragma once
#include "Framework/GameObject.h"
#include "Framework//Vector.h"

class CannonBall : 
	public GameObject
{
public:
	CannonBall();
	~CannonBall();
	void update(float dt) override;
	void setWindow(sf::RenderWindow* hwnd);

protected:
	sf::RenderWindow* window;
	bool dragStarted;
	float scale;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	sf::Vector2f mouseStartPos;
};

