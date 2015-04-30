#ifndef EXPLOSIONPARTICAL_HPP_INCLUDED
#define EXPLOSIONPARTICAL_HPP_INCLUDED
#include "BulletEntity.hpp"
class ExplosionPartical: public BulletEntity {

private:
    int Life_Span;
    bool Hurt_Player;
    bool Hurt_Enemy;

public:
    virtual bool Draw();
    virtual bool DefaultMove();
    ExplosionPartical(JAMCT_Logger *in_logger,int startx,int starty,int heading_direction,int life_span, bool hurt_good, bool hurt_bad);
    virtual void Colision(Entity *colided_with);

};


#endif // EXPLOSIONPARTICAL_HPP_INCLUDED
