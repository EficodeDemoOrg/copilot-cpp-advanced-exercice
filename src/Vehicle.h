#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
public:
	Vehicle(int position, int speed);

	int getPosition() const;
	int getSpeed() const;

	void updateSpeed(int maxSpeed, int distanceToNext);
	void updatePosition(int roadLength);

private:
	int position;
	int speed;
};

#endif
