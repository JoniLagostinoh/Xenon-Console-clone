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
        
    }
 
    int World::countShots() const
    {
        int count = 0;
        for (Entity* e : entities)
        {
            //Cast each entity and check if it's of type Shot
        }
    }// uses dynamic_cast
    
    int World::countEnemies() const
    {
        int count = 0;
        for (const Entity* e : entities)
        {
            //
        }
    }// uses dynamic_cast
    
   
 
 SpaceShip* World::findShip()
 {
     if (entities.size() != 0)
     {
         for (Entity* e : entities)
         {
             //
         }
     }
     else
     {
         
             throw std::invalid_argument("No entities found");
  
     }
 }// uses dynamic_cast; nullptr if there is none
};
