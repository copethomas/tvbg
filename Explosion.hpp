#ifndef EXPLOSION_HPP_INCLUDED
#define EXPLOSION_HPP_INCLUDED
#include "ExplosionPartical.hpp"
#include "World.hpp"
#include <vector>
class Explosion : public Entity {

private:
    World *theWorld;

public:
    Explosion(JAMCT_Logger *in_logger,int startx,int starty,int partical_count,int life_span, bool hurt_good, bool hurt_bad, World *in_theWorld);

};


#endif // EXPLOSION_HPP_INCLUDED
