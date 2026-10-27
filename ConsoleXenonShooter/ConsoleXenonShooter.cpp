#include <iostream>
#include <stdexcept>
#include "Entity.h"
#include "Gun.h"
#include "World.h"
#include "SpaceShip.h"


int main() {
    using namespace ConsoleXenonShooter;
 
    constexpr double fps = 60.0;
    constexpr double deltaTime = 1.0 / fps;
    
 
    try {
        World world{800.0, 600.0};
 
        world.add(new SpaceShip{Vector2D{100.0, 300.0},
                                Gun{GunType::light, 0.5, 20}});
        
        world.add(new Enemy{Vector2D{790.0, 300.0},
                            Vector2D{-40.0, 0.0}, 5.0});
 
       
        int frame = 0;
        constexpr double simulationTime = 10.0;
        
        while (frame * deltaTime < simulationTime)
        {
            
            
            // Fire once every second of simulated time
            if (frame % 60 == 0)
            {
                if (auto* ship = world.findShip())
                    if (Shot* shot = ship->fire())
                        world.add(shot); // World takes ownership
            }
            
            
            world.update(deltaTime);
            ++frame;
        }

        world.print();
        std::cout << "Shots: "  << world.countShots()   << "\n";
        std::cout << "Enemies: "<< world.countEnemies() << "\n";
        if (auto* ship = world.findShip())
            std::cout << "Ship found!\n";
    }
        
        
    
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid setup: " << e.what() << "\n";
        return 1;
    }
 
    return 0;
}
