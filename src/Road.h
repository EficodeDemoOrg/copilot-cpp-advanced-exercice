#ifndef ROAD_H
#define ROAD_H

#include "Vehicle.h"
#include <vector>
#include <memory>

class Road {
public:
	Road(int length);

	void addVehicle(int position, int speed);
	void update();
	void print() const;
	const std::vector<std::shared_ptr<Vehicle>> &getVehicles() const { return vehicles; }

private:
	int length;
	std::vector<std::shared_ptr<Vehicle>> vehicles;
};

#endif