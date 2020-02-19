#include "CannonBall.h"
#include "Framework/Vector.h"

CannonBall::CannonBall()
{
	// initialise gravity value (gravity 9.8, 200 scale, 200 p/s this will need to be uniform)
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
}

CannonBall::~CannonBall()
{

}

void CannonBall::setWindow(sf::RenderWindow* hwnd)
{
	window = hwnd;
}

void CannonBall::update(float dt)
{
	if (input->isMouseLDown())
	{
		if (!dragStarted)
		{
			dragStarted = true;
			mouseStartPos = sf::Vector2f(input->getMouseX(), input->getMouseY());
		}
	}
	else if (dragStarted)
	{
		dragStarted = false;
		float dragDistance = sqrt((sf::Mouse::getPosition().x - mouseStartPos.x) * (sf::Mouse::getPosition().x - mouseStartPos.x) + (sf::Mouse::getPosition().y - mouseStartPos.y) * (sf::Mouse::getPosition().y - mouseStartPos.y));
		sf::Vector2f direction = sf::Vector2f(input->getMouseX(), input->getMouseY()) - mouseStartPos;
		direction = Vector::normalise(direction);
		stepVelocity = direction * dragDistance;
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
