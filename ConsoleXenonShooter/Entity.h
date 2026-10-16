// Entity.hpp
#ifndef XENON_ENTITY_HPP
#define XENON_ENTITY_HPP


#include "Vector2D.h" 

namespace ConsoleXenonShooter {
 
    class Entity {
    public:
        Entity(Vector2D position, Vector2D velocity);
        virtual ~Entity() = default;
 
        virtual void update(double deltaTime) = 0;   // pure virtual
        virtual void print() const = 0;              // pure virtual
 
        
        
        virtual Vector2D getPosition() const {return position;}
        virtual Vector2D getVelocity() const { return velocity;}


        void setVelocity(Vector2D vel);
        void setPosition(Vector2D pos);
        
        bool isActive() const;
        void deactivate();
 
        void move(double deltaTime);   // position += velocity * deltaTime
 
   // private:
        Vector2D position;
        Vector2D velocity;
        bool active{true};
    };
 
    
    
    
    
    struct Shot : Entity
    {
        Shot(Vector2D position, Vector2D velocity, double power);
    private:
        double power;
       
        
        
    protected:
        void update(double deltaTime) override;
        void print() const override;
        double getPower() const {return power;}
    };
    
    
    
    
    
    struct Enemy : Entity
    {
 
        Enemy(Vector2D position, Vector2D velocity, double health);
    
    private:
        double health;
        Vector2D velocity_;
        Vector2D position_;

    protected:
        void update(double deltaTime) override;
        void print() const override;
        
        
    };
    
}
 
#endif