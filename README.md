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
   git clone [https://github.com/EficodeDemoOrg/copilot-cpp-exercise](https://github.com/EficodeDemoOrg/copilot-cpp-exercise)
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

```text
..V.....V...........
.....V......V.......
.........V.......V..
```

Here, `.` represents an empty road cell, and `V` represents a vehicle.

## Explore with GitHub Copilot: Development Directions

This project serves as a foundational platform for a car simulation. With GitHub Copilot, you can significantly accelerate the exploration of more complex features and behaviors. Here are several development directions you can pursue, using Copilot to help generate code, suggest algorithms, and refactor existing structures:

1.  **Advanced Road Networks and Intersections:**
    * **Direction:** Evolve the current circular road into a 2D grid or a more complex graph-based road network.
    * **Exploration:** Investigate how to represent intersections, implement traffic light systems, or define priority rules for merging traffic. Consider how vehicles will navigate these new structures and how their awareness of the road layout needs to change.

2.  **Diverse Vehicle Behaviors and Types:**
    * **Direction:** Introduce a wider variety of vehicles and more nuanced driving behaviors.
    * **Exploration:** Create new vehicle classes (e.g., trucks, buses, emergency vehicles, motorcycles) with unique attributes (size, speed, acceleration, braking power, turning radius). Implement varied driver profiles, such as cautious, aggressive, or eco-friendly, influencing decision-making like overtaking, lane preference, or maintaining distance.

3.  **Dynamic Environmental Factors and Events:**
    * **Direction:** Incorporate environmental elements and unexpected events that can change during the simulation and affect vehicle dynamics or road conditions.
    * **Exploration:** Model weather conditions (rain, snow, fog) impacting visibility and friction, or introduce road incidents (e.g., accidents, construction zones, potholes) that dynamically alter the road network, speed limits, or require vehicles to reroute.

4.  **Sophisticated Sensor Models and Decision Making:**
    * **Direction:** Enhance how vehicles perceive their environment and make decisions based on that perception.
    * **Exploration:** Implement more realistic sensor models for vehicles (e.g., limited range lidar, camera field of view, noisy sensor data). Based on this perceived environment, develop more complex decision-making logic for maneuvers like lane changing, gap acceptance, or emergency braking, perhaps exploring concepts from autonomous driving.

5.  **Comprehensive Simulation Metrics and Analysis:**
    * **Direction:** Expand the data collection and analysis capabilities of the simulation to gain deeper insights into traffic dynamics.
    * **Exploration:** Calculate and track metrics such as average travel time, fuel consumption estimates, emissions levels based on driving style, traffic density, throughput at specific points, or queue lengths. Consider how to output this data (e.g., CSV, JSON) for external analysis or visualize it over time.

6.  **Enhanced Visualization and User Interaction:**
    * **Direction:** Move beyond basic console output to create a more engaging and informative representation of the simulation.
    * **Exploration:** Develop richer text-based visualizations in the console (e.g., using ANSI escape codes for colors or different characters for vehicle states). Investigate integrating simple 2D graphics libraries (e.g., SFML, SDL) or even exploring pathways to generate data for web-based visualizations to display vehicle movements and road states more intuitively. Consider adding interactive controls to the simulation (e.g., pausing, stepping, adding vehicles dynamically, changing global parameters).

7.  **Object-Oriented Design Refinement and Scalability:**
    * **Direction:** Utilize advanced OOP principles and software design patterns to create a more flexible, maintainable, and extensible codebase capable of handling increased complexity.
    * **Exploration:** Apply design patterns (e.g., Strategy for different driving behaviors or pathfinding algorithms, Observer for event handling, Factory for vehicle creation). Use polymorphism extensively for handling different vehicle types, road segment types, or intersection logic through common interfaces. Focus on modularity to ensure components can be developed and tested independently.

8.  **Pathfinding and Destination-Oriented Travel:**
    * **Direction:** In more complex road networks (like a grid or graph), enable vehicles to have specific origins and destinations.
    * **Exploration:** Implement pathfinding algorithms (e.g., A\*, Dijkstra's) to allow vehicles to calculate and follow routes to their assigned destinations. Consider how vehicles might react to dynamic changes in the network, such as new obstructions, and recalculate their paths.

These directions are starting points. Feel free to combine them or invent your own extensions. GitHub Copilot can be a powerful partner in brainstorming solutions, writing boilerplate code, implementing algorithms, suggesting C++ idioms, and even helping you debug as you expand the simulation's capabilities.

## Notes
While the initial setup and basic simulation can be explored relatively quickly, the development directions outlined above offer many hours of potential extension and learning. These advanced targets are especially well-suited for leveraging GitHub Copilot to accelerate development, explore complex C++ implementations, and deepen your understanding of simulation design.