#include "World.h"
#include "Entity.h"
#include "SpaceShip.h"
#include <iostream>
#include <stdexcept>
#include "Vector2D.h"

namespace ConsoleXenonShooter
{
    
    World::World(double width, double height) : width(width), height(height) //Initializing width and height (lovely)
    {
        if (width <= 0 || height <= 0)
        {
            throw std::invalid_argument("width and height must be greater than 0");
        }
        
    }// throws if width or height <= 0
    
    
   World::~World()
    {
        
        for (Entity* e : entities)
        {
            delete e;
        }
        
    } // deletes every entity still owned
 
    
    
    void World::add(Entity* entity)
    {
        if (entity != nullptr)
        {
            entities.push_back(entity);
        }
        
    }// World takes ownership; ignores nullptr
    
    
    void World::update(double deltaTime)
    {
        for (Entity* e : entities)
        {
            e->update(deltaTime);
        }
    }
    
    //Todo: Finish World Implementation
    void World::print() const
    {
        std::cout << "World " << width << "x" << height << " with " << entities.size() << " entities: \n";
        for (const Entity* e : entities)
        {
            e->print();
        }
    }
 
    int World::countShots() const
    {
        int count = 0;
        for (const Entity* e : entities)
        {
            if (dynamic_cast<const Shot*>(e) != nullptr)
                ++count;
        }
        return count;
    }// uses dynamic_cast
    
    int World::countEnemies() const
    {
        int count = 0;
        for (const Entity* e : entities)
        {
            if (dynamic_cast<const Enemy*>(e) != nullptr) ++count;
        }
        return count;
    }// uses dynamic_cast
    
   
 
 SpaceShip* World::findShip()
 {
     
         for (Entity* e : entities)
         {
             if (auto* ship = dynamic_cast<SpaceShip*>(e))
             {
                 return ship;   
             }
         }
        return nullptr; //Unverified: Rider recomended
        
 }// uses dynamic_cast; nullptr if there is none
};
