#include <iostream>
#include <stdexcept>
#include "Enemy.cpp"
#include "Gun.h"
#include "SpaceShip.cpp"
#include "World.cpp"

int main() {
    using namespace ConsoleXenonShooter;
 
    constexpr double fps = 60.0;
    constexpr double deltaTime = 1.0 / fps;
    constexpr double simulationTime = 10.0;
 
    try {
        World world{800.0, 600.0};
 
        world.add(new SpaceShip{Vector2D{100.0, 300.0},
                                Gun{GunType::light, 0.5, 20}});
        world.add(new Enemy{Vector2D{790.0, 300.0},
                            Vector2D{-40.0, 0.0}, 5.0});
 
        // ... simulation loop ...
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid setup: " << e.what() << "\n";
        return 1;
    }
 
    return 0;
}
