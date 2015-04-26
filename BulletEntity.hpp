#ifndef BULLETENTITY_HPP_INCLUDED
#define BULLETENTITY_HPP_INCLUDED
#include "MovableEntity.hpp"
#include "JAMCT_Logger.hpp"
class BulletEntity: public MovableEntity {

protected:
    int Damage = 0;


public:
    virtual bool Draw();
    virtual bool DefaultMove();
    BulletEntity(JAMCT_Logger *in_logger,int startx,int starty,int heading_direction);

};


#endif // BULLETENTITY_HPP_INCLUDED
