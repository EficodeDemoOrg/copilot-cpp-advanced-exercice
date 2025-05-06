#include "Vehicle.h"
#include <algorithm>

Vehicle::Vehicle(int position, int speed) : position(position), speed(speed) {}

int Vehicle::getPosition() const
{
	return position;
}

int Vehicle::getSpeed() const
{
	return speed;
}

void Vehicle::updateSpeed(int maxSpeed, int distanceToNext)
{
	if (distanceToNext > speed + 1)
		speed = std::min(speed + 1, maxSpeed);
	else if (distanceToNext <= speed)
		speed = std::max(speed - 1, 0);
}

void Vehicle::updatePosition(int roadLength)
{
	position = (position + speed) % roadLength;
}