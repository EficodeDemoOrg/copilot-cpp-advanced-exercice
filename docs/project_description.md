
# Project Description

## Purpose
This project simulates the movement of vehicles on a circular road. It is designed for both human and AI agent analysis, with a modular structure and clear separation of concerns. The simulation models vehicle behavior (acceleration, deceleration, position updates) and outputs the road state at each step.

## Core Entities
- **Vehicle**: Encapsulates position and speed. Updates its speed based on the distance to the next vehicle and a maximum speed. Updates its position, wrapping around the road.
- **Road**: Manages a collection of vehicles on a circular road of configurable length. Updates all vehicles and prints the road state.
- **Simulation Loop**: The main loop (in `main.cpp`) that advances the simulation, prints the road, and tracks vehicle positions over time.

## Behavior Summary
- Vehicles accelerate if space ahead is clear, decelerate if too close to the next vehicle, or maintain speed otherwise.
- The road is circular: positions wrap around at the end.
- The simulation prints the road state at each step, showing vehicle positions.

## File Structure
- `src/Vehicle.h` / `src/Vehicle.cpp`: Vehicle class definition and implementation.
- `src/Road.h` / `src/Road.cpp`: Road class definition and implementation.
- `src/main.cpp`: Simulation entry point and main loop.
- `CMakeLists.txt`: Build configuration.

## AI Agent Guidance
- The codebase is modular and extensible. New vehicle types, road features, or simulation rules can be added with minimal changes.
- Each class encapsulates its own logic and state, supporting isolated analysis and modification.
- The architecture is suitable for automated reasoning, code generation, and extension by AI agents.
