#ifndef ENEMYSHIP_HPP_INCLUDED
#define ENEMYSHIP_HPP_INCLUDED
#include "PlayerShip.hpp"
class EnemyShip: public Ship {

private:
    PlayerShip *trackingPlayer;

public:
    virtual bool Draw();
    virtual bool DefaultMove();
    virtual bool Shoot();
    EnemyShip(JAMCT_Logger *in_logger,int startx,int starty,int in_health,World *home_world,PlayerShip *thePlayer);
};


#endif // ENEMYSHIP_HPP_INCLUDED
