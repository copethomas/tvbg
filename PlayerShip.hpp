#ifndef PLAYERSHIP_HPP_INCLUDED
#define PLAYERSHIP_HPP_INCLUDED
#include "Ship.hpp"
class PlayerShip: public Ship {

public:
    virtual bool Draw();
    virtual bool DefaultMove();
    virtual bool Shoot();
    PlayerShip(JAMCT_Logger *in_logger,int startx,int starty,int in_health,World *home_world);

};
#endif // PLAYERSHIP_HPP_INCLUDED
