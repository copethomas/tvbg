#include "Explosion.hpp"

Explosion::Explosion(JAMCT_Logger* in_logger, int startx, int starty, int partical_count, int life_span, bool hurt_good, bool hurt_bad, World *in_theWorld): Entity(in_logger,startx,starty)
{
    Explosion::theWorld = in_theWorld;
    int current_direction = 0;
    while (partical_count!=0) {
        ExplosionPartical *partical = new ExplosionPartical(in_logger,startx,starty,current_direction,life_span,hurt_good,hurt_bad);
        theWorld->AddEntity(partical);
        current_direction +=45;
        if (current_direction > 315) {current_direction = 0;}
        partical_count--;
    }
    Explosion::SetDead(true);
}
