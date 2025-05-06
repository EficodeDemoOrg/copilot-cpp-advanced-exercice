# Project Architecture

```mermaid
classDiagram
    class Vehicle {
        - int position
        - int speed
        + Vehicle(int position, int speed)
        + int getPosition() const
        + int getSpeed() const
        + void updateSpeed(int maxSpeed, int distanceToNext)
        + void updatePosition(int roadLength)
    }
    class Road {
        - int length
        - std::vector<shared_ptr<Vehicle>> vehicles
        + Road(int length)
        + void addVehicle(int position, int speed)
        + void update()
        + void print() const
        + const std::vector<shared_ptr<Vehicle>>& getVehicles() const
    }
    class Main {
        + int main()
    }
    Road "1" *-- "many" Vehicle : manages
    Main ..> Road : uses
    Main ..> Vehicle : uses
```

## Architecture Notes
- The `Main` program creates a `Road` and adds `Vehicle` instances.
- `Road` manages the collection of `Vehicle` objects and updates their states.
- `Vehicle` encapsulates its own state and update logic.
- The architecture is modular and suitable for AI-driven code analysis and extension.
