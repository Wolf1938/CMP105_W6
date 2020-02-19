#pragma once
#include "Framework//GameObject.h"
#include "Framework//vector.h"

class Ball :
	public GameObject
{
public:
	Ball();
	~Ball();

	void update(float dt) override;
	void setWindow(sf::RenderWindow* hwnd);

	sf::RenderWindow* window;
	float scale;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
};

