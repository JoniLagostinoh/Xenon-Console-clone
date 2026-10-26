#include "SpaceShip.h"
#include <iostream>

namespace ConsoleXenonShooter
{
    SpaceShip::SpaceShip(Vector2D position, Gun gun)
        : Entity(position, Vector2D{0.0, 0.0}), gun(gun) {}

    
    void SpaceShip::update(double deltaTime) { Entity::move(deltaTime); }

    
    
    void SpaceShip::print() const
    {
        std::cout << "SpaceShip at (" << position.x << ", " << position.y << ") ammo=" << gun.currentAmmo << "/" << gun.getMaxAmmo() << "\n";
    }

    
    Shot* SpaceShip::fire()
    {
        if (gun.currentAmmo <= 0) return nullptr;
        --gun.currentAmmo;
        
        
        return new Shot
        {
            Vector2D{position.x + 10.0, position.y},  // muzzle
            Vector2D{300.0, 0.0},                  // Direction (right) 
            powerOf(gun.getType())
        };
    }

    void SpaceShip::upgradeGun(const Gun& newGun) { gun = newGun; }
    void SpaceShip::reloadGun()                   { gun.currentAmmo = gun.getMaxAmmo(); }
}