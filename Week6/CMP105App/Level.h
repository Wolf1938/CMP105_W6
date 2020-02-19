#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Ball.h"
#include "HomingMissile.h"
#include "CannonBall.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// More level variables
	Ball ball;
	sf::Texture ballTexture;
	HomingMissile missile;
	CannonBall cannonBall;
};