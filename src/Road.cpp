#include "Road.h"
#include <iostream>

Road::Road(int length) : length(length) {}

void Road::addVehicle(int position, int speed)
{
	vehicles.push_back(std::make_shared<Vehicle>(position, speed));
}

void Road::update()
{
	for (size_t i = 0; i < vehicles.size(); ++i) {
		int nextPosition = vehicles[(i + 1) % vehicles.size()]->getPosition();
		int distanceToNext = (nextPosition - vehicles[i]->getPosition() + length) % length;
		vehicles[i]->updateSpeed(5, distanceToNext);
	}

	for (auto &vehicle : vehicles)
		vehicle->updatePosition(length);
}

void Road::print() const
{
	std::vector<char> roadState(length, '.');
	for (const auto &vehicle : vehicles)
		roadState[vehicle->getPosition()] = 'V';

	for (char cell : roadState)
		std::cout << cell;
	std::cout << std::endl;
}