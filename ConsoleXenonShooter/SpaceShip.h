#pragma once
#include "Entity.h"
#include "Gun.h"

namespace ConsoleXenonShooter
{
    class SpaceShip : public Entity
    {
    public:
        SpaceShip(Vector2D position, Gun gun);

        void update(double deltaTime) override;
        void print() const override;

        Shot* fire();
        void upgradeGun(const Gun& newGun);
        void reloadGun();
        const Gun& getGun() const { return gun; }

    private:
        Gun gun;
    };
}