#pragma once
#include <vector>

namespace ConsoleXenonShooter
{
    class Entity;
    class SpaceShip;

    class World
    {
    public:
        World(double width, double height);   
        ~World();                             

        
        //Singleton
        World(const World&) = delete;
        World& operator=(const World&) = delete;

        
        void add(Entity* entity);             // takes ownership, ignores nullptr
        void update(double deltaTime);
        void print() const;

        
        int countShots() const;
        int countEnemies() const;
        SpaceShip* findShip();

        
    private:
        std::vector<Entity*> entities;
        double width;
        double height;
    };
}