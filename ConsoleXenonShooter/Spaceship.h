#pragma once
#include "Entity.h"
#include "Gun.h"

using namespace ConsoleXenonShooter;

class Spaceship : public Entity
{
public:
   
    
    virtual void update(float deltatime);
    Shot* fire();
    
    void upgradeGun(Gun* gun);

    void reloadgun(Gun* gun);
    
    const Gun& getGun();
    
   auto print(Vector2D position, GunType gunType, Gun ammo);
    
private:
    
};
