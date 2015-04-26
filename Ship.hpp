#ifndef SHIP_HPP_INCLUDED
#define SHIP_HPP_INCLUDED
#include "MovableEntity.hpp"
#include "JAMCT_Logger.hpp"
#include "World.hpp"
class Ship: public MovableEntity {

protected:
    int Health;
    World *theWorld;
    int Height = 30;
    int Width = 30;

public:
    virtual bool Draw();
    virtual bool DefaultMove();
    virtual bool Shoot();
    void DamageShip(int hitDamage);
    Ship(JAMCT_Logger *in_logger,int startx,int starty,int in_health,World *home_world);

};

#endif // SHIP_HPP_INCLUDED
