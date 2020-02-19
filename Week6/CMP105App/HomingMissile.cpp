#include "HomingMissile.h"

HomingMissile::HomingMissile()
{
	speed = 100;
}

HomingMissile::~HomingMissile()
{

}

void HomingMissile::update(float dt)
{
	// calculate direction and move
	sf::Vector2f direction = target - getPosition();
	direction = Vector::normalise(direction);
	velocity = (direction * speed);
	setPosition(getPosition() + (velocity * dt));

	// if object is close enough to target
	if (Vector::magnitude(target - getPosition()) < 10.f)
	{
		setPosition(target);
		speed = 100;
	}
}

void HomingMissile::setTarget(sf::Vector2f trgt)
{
	target = trgt;
}