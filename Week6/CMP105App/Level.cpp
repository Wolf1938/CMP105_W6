#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ball.setSize(sf::Vector2f(50, 50));
	ball.setPosition(200, 200);
	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	ball.setTexture(&ballTexture);
	ball.setInput(input);
	ball.setWindow(window);

	missile.setSize(sf::Vector2f(60, 60));
	missile.setPosition(50, 50);
	missile.setTexture(&ballTexture);
	missile.setTarget(sf::Vector2f(600, 600));

	cannonBall.setSize(sf::Vector2f(20, 20));
	cannonBall.setPosition(100, 400);
	cannonBall.setTexture(&ballTexture);
	cannonBall.setInput(input);
	cannonBall.setWindow(window);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	ball.update(dt);

	missile.setTarget(sf::Vector2f(input->getMouseX(), input->getMouseY()));
	missile.speed += dt * 100;

	missile.update(dt);

	cannonBall.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball);
	window->draw(missile);
	window->draw(cannonBall);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}