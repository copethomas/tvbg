#ifndef ENEMYFIGHTERBULLET_HPP_INCLUDED
#define ENEMYFIGHTERBULLET_HPP_INCLUDED
#include "BulletEntity.hpp"
class EnemyFighterBullet: public BulletEntity{

private:
    int Colour_Modifier = 0;

public:
    EnemyFighterBullet(JAMCT_Logger *in_logger,int startx,int starty,int heading_direction);
    virtual void Colision(Entity *colided_with);
    virtual bool Draw();

};

#endif // ENEMYFIGHTERBULLET_HPP_INCLUDED
