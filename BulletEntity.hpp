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
    virtual void Colision(Entity *colided_with);
    void DrawCircle(float cx, float cy, float rad, int num_segments,float r,float g, float b);
};


#endif // BULLETENTITY_HPP_INCLUDED
