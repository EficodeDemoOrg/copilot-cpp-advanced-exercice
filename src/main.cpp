#include <thread>
#include <chrono>
#include "Vehicle.h"
#include "Road.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <map>

int main()
{
	Road road(20);
	road.addVehicle(0, 1);
	road.addVehicle(5, 2);

	int step_delay_ms = 1000;
	int total_steps = 10;

	std::cout << "Number of steps: " << total_steps << std::endl;

	int padding = std::to_string(total_steps).length();
	std::map<int, int> previous_positions;

	for (int step = 0; step < total_steps; ++step) {
		std::cout << "Step " << std::setw(padding) << (step + 1) << " of " << total_steps << ": ";
		road.update();
		road.print();

		for (size_t i = 0; i < road.getVehicles().size(); ++i) {
			int current_position = road.getVehicles()[i]->getPosition();
			int previous_position = previous_positions.count(i) ? previous_positions[i] : current_position;
			std::cout << "vehicle" << i << "(" << current_position << ") from vehicle" << i << "(" << previous_position << ")" << std::endl;
			previous_positions[i] = current_position;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(step_delay_ms));
	}

	return 0;
}