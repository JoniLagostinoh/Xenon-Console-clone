#include "Entity.h"

#include <iostream>

namespace ConsoleXenonShooter {

    
    
    
    Entity::Entity(Vector2D position, Vector2D velocity)
        : position(position), velocity(velocity) {}

    
    
    void Entity::setVelocity(Vector2D vel) { velocity = vel; }
    void Entity::setPosition(Vector2D pos) { position = pos; }

    bool Entity::isActive() const { return active; }
    void Entity::deactivate() { active = false; }

    void Entity::move(double deltaTime) {
        position += velocity * deltaTime;
    }

    
    
   
    Shot::Shot(Vector2D position, Vector2D velocity, double power)
        : Entity(position, velocity) {}

    void Shot::update(double deltaTime) {
        Entity::move(deltaTime);           
    }

    void Shot::print() const {
        std::cout << "Shot at (" << position.x << ", "
                  << position.y << ") power=" << power << "\n";
    }
    
    
    

   
   
    Enemy::Enemy(Vector2D position, Vector2D velocity, double health)
        : Entity(position, velocity) {}

    void Enemy::update(double deltaTime) {
        Entity::move(deltaTime);
    }

    void Enemy::print() const {
        std::cout << "Position: " << position.x << ", " << position.y << "\n";
        
        std::cout << "Health=" << health << "\n";
    }

}
