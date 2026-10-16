#pragma once
#include <iostream>
#include <algorithm>


enum class GunType { light, medium, heavy };
 
double powerOf(GunType type);   // light = 1, medium = 2, heavy = 4 (use a switch)

class Gun {
    
    
    private:
    GunType type;
    double cooldown;
    int maxAmmo;
    
    
    
    
    
public:
    Gun(GunType type, double cooldown, int maxAmmo);

    GunType getType()     const { return type; }
    double  getCooldown() const { return cooldown; }
    int     getMaxAmmo()  const { return maxAmmo; }

   
    
    
};

