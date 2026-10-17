#include "Gun.h"

double powerOfGun(GunType type) {
    switch (type) {
    case GunType::light:  return 1.0;
    case GunType::medium: return 2.0;
    case GunType::heavy:  return 4.0;
    }
    throw std::invalid_argument("Invalid Gun Type");
}

Gun::Gun(GunType type, double cooldown, int maxAmmo) : type(type), cooldown(cooldown), maxAmmo(maxAmmo)
{
    if (cooldown < 0.0 || maxAmmo <= 0)
    {
        throw std::invalid_argument("Gun cooldown or Arguments invalid");
    }
}