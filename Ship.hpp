#ifndef SHIP_HPP_INCLUDED
#define SHIP_HPP_INCLUDED
#include "MovableEntity.hpp"
#include "JAMCT_Logger.hpp"
class Ship: public MovableEntity {

protected:
    int Health;

public:
    virtual bool Draw();
    virtual bool DefaultMove();
    virtual bool MoveUp();
    virtual bool MoveDown();
    virtual bool MoveLeft();
    virtual bool MoveRight();
    void DamageShip(int hitDamage);
    explicit Ship(JAMCT_Logger *in_logger,int startx,int starty,int shipHealth);
};

#endif // SHIP_HPP_INCLUDED
