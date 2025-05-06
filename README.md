# Car Simulation Exercise

This exercise involves simulating cars moving on a simple road network using C++ and CMake as the build tool. The goal is to model vehicles on a circular road and implement basic rules for their movement.

## Features
- **Road Network**: A circular road represented as a 1D array.
- **Vehicle Class**: Vehicles with position, speed, and simple movement rules:
  - Accelerate if the space ahead is clear.
  - Decelerate if the vehicle ahead is too close.
  - Maintain current speed otherwise.
  - Maximum speed limit.
- **Simulation Loop**: Updates vehicle states and prints the road state to the console.

## Requirements
- **C++ Compiler**: A C++17-compatible compiler (e.g., GCC, Clang).
- **CMake**: Version 3.10 or higher.

## Setup Instructions
1. **Clone the repository**:
   Open a terminal and run the following commands to clone the repository and navigate to the project folder:
   ```bash
   git clone https://github.com/EficodeDemoOrg/copilot-cpp-exercise
   cd copilot-cpp-exercise
   ```

2. **Create a build directory**:
   Create a separate directory for the build files to keep the project organized:
   ```bash
   mkdir build
   cd build
   ```

3. **Run CMake to configure the project**:
   Use CMake to generate the necessary build files:
   ```bash
   cmake ..
   ```

4. **Build the project**:
   Compile the project using the generated build files:
   ```bash
   cmake --build .
   ```

5. **Run the simulation**:
   Execute the compiled program to start the simulation:
   ```bash
   ./CarSimulation
   ```

## Output
The simulation prints the state of the road at each step. For example:
```
..V.....V...........
.....V......V.......
.........V.......V..
```
Here, `.` represents an empty road cell, and `V` represents a vehicle.

## Extensions
You can extend the exercise with the following features:
- **Intersections**: Implement a 2D grid with traffic lights or priority rules.
- **Multiple Lanes**: Extend the road model to support multiple lanes.
- **Different Vehicle Types**: Add cars and trucks with varying speed and acceleration profiles.
- **Driver Behavior**: Introduce randomness in vehicle behavior.
- **Pathfinding**: Assign destinations to vehicles in a grid network.
- **Metrics**: Calculate average speed, throughput, and queue lengths.
- **Visualization**: Add basic graphics or enhanced console output.
- **OOP Refinement**: Use polymorphism for different vehicle types or intersection logic.

## Notes
This exercise is designed to be completed in approximately 2 hours and is compatible with GitHub Copilot for assistance.