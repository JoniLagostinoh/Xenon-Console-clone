#include <vector>
#include "Entity.h"
#include "SpaceShip.h"
#include "Vector2D.h"


class World {
public:
    World(double width, double height);   // throws if width or height <= 0
    ~World();                             // deletes every entity still owned
 
    void add(Entity* entity);             // World takes ownership; ignores nullptr
    void update(double deltaTime);
    void print() const;
 
    int countShots() const;     // uses dynamic_cast
    int countEnemies() const;   // uses dynamic_cast
    SpaceShip* findShip();      // uses dynamic_cast; nullptr if there is none
 
private:
    std::vector<Entity*> entities;   // World owns these
    double width;
    double height;
};
