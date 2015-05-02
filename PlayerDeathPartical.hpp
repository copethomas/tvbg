#ifndef PLAYERDEATHPARTICAL_HPP_INCLUDED
#define PLAYERDEATHPARTICAL_HPP_INCLUDED
#include "BulletEntity.hpp"
class PlayerDeathPartical: public BulletEntity{

private:
    int SpinDirection = 0;

public:
    virtual bool Draw();
    virtual bool DefaultMove();
    PlayerDeathPartical(JAMCT_Logger *in_logger,int startx,int starty,int heading_direction,int speed);
    void Colision(Entity* colided_with);
};


#endif // PLAYERDEATHPARTICAL_HPP_INCLUDED
