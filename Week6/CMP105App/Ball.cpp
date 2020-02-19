#include "Ball.h"

Ball::Ball()
{
	// initialise gravity value (gravity 9.8, 200 scale, 200 p/s this will need to be uniform)
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
}

Ball::~Ball()
{

}


void Ball::setWindow(sf::RenderWindow* hwnd)
{
	window = hwnd;
}

void Ball::update(float dt)
{
	if (input->isMouseLDown())
	{
		setPosition((float)input->getMouseX(), (float)input->getMouseY());
	}

	if (input->isKeyDown(sf::Keyboard::Space))
	{
		stepVelocity = sf::Vector2f(0, -1.f) * scale;
	}

	// Apply gravity force, increasing velocity
	// Move shape by new velocity
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt; //ut+ 1/2at^2
	stepVelocity += gravity * dt; // v = u + at  note the += is not =
	setPosition(getPosition() + pos);

	// Check for collision with window
	if (getPosition().y >= window->getSize().y - getSize().y)
	{
		setPosition(getPosition().x, window->getSize().y - getSize().y);
		stepVelocity = sf::Vector2f(stepVelocity.x, -stepVelocity.y) * 0.8f;
	}
	else if (getPosition().x >= window->getSize().x - getSize().x)
	{
		setPosition(window->getSize().x - getSize().x, getPosition().y);
		stepVelocity = sf::Vector2f(-stepVelocity.x, stepVelocity.y) * 0.8f;
	}
	else if (getPosition().y <= 0)
	{
		setPosition(getPosition().x, 0);
		stepVelocity = sf::Vector2f(stepVelocity.x, -stepVelocity.y) * 0.8f;
	}
	else if (getPosition().x < 0)
	{
		setPosition(0, getPosition().y);
		stepVelocity = sf::Vector2f(-stepVelocity.x, stepVelocity.y) * 0.8f;
	}
}
