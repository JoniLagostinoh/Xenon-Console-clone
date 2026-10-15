// Entity.hpp
#ifndef XENON_ENTITY_HPP
#define XENON_ENTITY_HPP


#include <algorithm>
#include <iostream>

#include "Vector2D.h" 

namespace ConsoleXenonShooter {
 
    class Entity {
    public:
        Entity(Vector2D position, Vector2D velocity);
        virtual ~Entity() = default;
 
        virtual void update(double deltaTime) = 0;   // pure virtual
        virtual void print() const = 0;              // pure virtual
 
        Vector2D getPosition() const;
        Vector2D getVelocity() const;
        void setVelocity(Vector2D velocity);
 
        bool isActive() const;
        void deactivate();
 
        void move(double deltaTime);   // position += velocity * deltaTime
 
   // private:
        Vector2D position;
        Vector2D velocity;
        bool active{true};
    };
 
    
    
    
    
    struct Shot : public Entity
    {
        public:
        Shot(Vector2D position, Vector2D velocity, double power);
        
        
        void update(double deltaTime) override
        {
            return position += velocity * deltaTime; 
        };
        
        Vector2D getPosition(Shot& shot) const; //Test, to be removed later
        
        
        Vector2D setPosition(Shot& shot, double deltaTime) const;
        
        
    };
    
    
    
    
    
    struct Enemy : public Entity
    {
        public:
        Enemy(Vector2D position, Vector2D velocity, double health);
    
        Vector2D getPosition() const {return this->position};
        
        void print() const override {std::cout << this->getPosition();}
        
    };
    
}
 
#endif