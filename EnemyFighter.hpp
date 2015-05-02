#ifndef ENEMYFIGHTER_HPP_INCLUDED
#define ENEMYFIGHTER_HPP_INCLUDED
#include "EnemyShip.hpp"
class EnemyFighter: public EnemyShip {

public:
    virtual bool Draw();
    virtual bool DefaultMove();
    virtual bool Shoot();
    EnemyFighter(JAMCT_Logger *in_logger,int startx,int starty,int in_health,World *home_world,PlayerShip *thePlayer);
    virtual void Colision(Entity *colided_with);
};


#endif // ENEMYFIGHTER_HPP_INCLUDED
