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

This project provides a solid starting point for a dynamic car simulation. Think of it as your creative canvas! With GitHub Copilot as your collaborative AI partner, you're empowered to rapidly prototype innovative features, implement sophisticated algorithms, and explore a multitude of exciting evolutionary paths for this simulation. To guide your journey, here are several development directions, thoughtfully sorted from lower to higher complexity. Each offers unique challenges and learning opportunities:

1.  **Comprehensive Simulation Metrics and Analysis:**
    * _Complexity: Low to Moderate_
    * **Direction:** Expand the data collection and analysis capabilities of the simulation to gain deeper insights into traffic dynamics.
    * **Exploration:** Start by tracking basic statistics like average speed, total vehicle count, or time to traverse the road. Progress to more detailed data such as traffic density, throughput at specific points, or average queue lengths. Investigate how to output this data (e.g., to the console in a structured way, or to a CSV file) for observation or external analysis.

2.  **Diverse Vehicle Behaviors and Types:**
    * _Complexity: Low to Moderate_
    * **Direction:** Introduce a wider variety of vehicles and more nuanced driving behaviors.
    * **Exploration:** Begin by creating new vehicle classes derived from the existing `Vehicle` class, giving them varied attributes like maximum speed, acceleration rates, or even size (though size impact would require more logic). Then, implement distinct driver profiles (e.g., a 'cautious' driver maintaining more distance, an 'aggressive' driver accelerating faster) that influence how vehicles react to their surroundings and follow rules.

3.  **Enhanced Visualization and User Interaction (Console Focus):**
    * _Complexity: Low to Moderate_
    * **Direction:** Move beyond the current basic console output to create a more engaging and informative representation of the simulation, and add simple ways to interact with it.
    * **Exploration:** Improve the console output with more detailed information per vehicle, use different characters for different vehicle types, or explore ANSI escape codes for colors if your terminal supports it. Consider adding basic keyboard interactions like pausing/resuming the simulation, stepping through it one update at a time, or adding new vehicles dynamically.

4.  **Object-Oriented Design Refinement and Expansion:**
    * _Complexity: Moderate_
    * **Direction:** Utilize advanced OOP principles and software design patterns to create a more flexible, maintainable, and extensible codebase.
    * **Exploration:** Refactor existing code to apply OOP principles more deeply (e.g., ensuring strong encapsulation, clear responsibilities). Explore using polymorphism more extensively, perhaps for different vehicle update logic or for different types of road segments if you expand the road model. Consider implementing design patterns like the Strategy pattern for varied driving behaviors or a Factory pattern for vehicle creation.

5.  **Dynamic Environmental Factors and Events:**
    * _Complexity: Moderate to High_
    * **Direction:** Incorporate environmental elements and unexpected events that can change during the simulation and affect vehicle dynamics or road conditions.
    * **Exploration:** Introduce elements like changing weather conditions (e.g., "rain" reducing maximum speed or increasing braking distance) or simple road events like a temporary blockage on a road segment. This might involve creating a basic event management system or adding conditional logic to the simulation loop and vehicle update methods.

6.  **Advanced Road Networks and Intersections:**
    * _Complexity: High_
    * **Direction:** Evolve the current circular road into a 2D grid or a more complex graph-based road network.
    * **Exploration:** This involves significant data structure changes to represent the new road layout. Design and implement logic for intersections, which could include simple priority rules (e.g., yield to the right) or more complex systems like traffic lights. Vehicles would need enhanced logic to navigate these new structures.

7.  **Sophisticated Sensor Models and Decision Making:**
    * _Complexity: High_
    * **Direction:** Enhance how vehicles perceive their environment and make decisions based on that perception, moving towards more realistic autonomous agent behavior.
    * **Exploration:** Equip vehicles with more realistic sensor models, such as a limited forward perception range or a defined field of view, instead of perfect knowledge of the vehicle ahead. Develop more advanced AI for decision-making based on this imperfect information, such as more complex lane-changing logic (if multiple lanes are added) or more nuanced collision avoidance strategies.

8.  **Pathfinding and Destination-Oriented Travel:**
    * _Complexity: High_
    * **Direction:** In conjunction with more complex road networks (like a grid or graph from point 6), enable vehicles to have specific origins and destinations rather than just circulating.
    * **Exploration:** Implement pathfinding algorithms (like A* or Dijkstra's) to allow vehicles to calculate routes to their assigned destinations. This will require vehicles to store their path and follow it, potentially re-routing if their initial path becomes obstructed due to dynamic events.

These directions are starting points. Feel free to combine them or invent your own extensions. GitHub Copilot can be a powerful partner in brainstorming solutions, writing boilerplate code, implementing algorithms, suggesting C++ idioms, and even helping you debug as you expand the simulation's capabilities.

## Notes
While the initial setup and basic simulation can be explored relatively quickly, the development directions outlined above offer many hours of potential extension and learning. These advanced targets are especially well-suited for leveraging GitHub Copilot to accelerate development, explore complex C++ implementations, and deepen your understanding of simulation design.