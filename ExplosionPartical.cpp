#include "ExplosionPartical.hpp"
#include "Ship.hpp"
#include "PlayerShip.hpp"
#include "DrawUtil.hpp"
#include <GLFW/glfw3.h>
bool ExplosionPartical::Draw()
{
    DrawUtil_DrawSquare(XLocation,YLocation,Height,Width,1,1,0);
    return true;
}

bool ExplosionPartical::DefaultMove()
{
    MoveUp();
    ExplosionPartical::Life_Span -=1;
    if (ExplosionPartical::Life_Span <= 0) {
        ExplosionPartical::SetDead(true);
    }
}

ExplosionPartical::ExplosionPartical(JAMCT_Logger* in_logger, int startx, int starty, int heading_direction, int life_span, bool hurt_good, bool hurt_bad): BulletEntity(in_logger,startx,starty,heading_direction)
{
    ExplosionPartical::Life_Span = life_span;
    ExplosionPartical::Hurt_Player = hurt_good;
    ExplosionPartical::Hurt_Enemy = hurt_bad;
    ExplosionPartical::Height = 2;
    ExplosionPartical::Width = 2;
    ExplosionPartical::Speed = 20;
    ExplosionPartical::Damage = 25;
}

void ExplosionPartical::Colision(Entity* colided_with)
{
    if(Ship* bad_guy = dynamic_cast< Ship* >( colided_with )) {
        if (Hurt_Enemy) {
            bad_guy->DamageShip(this->GetDamage());
        }
    }
    if( PlayerShip* good_guy = dynamic_cast< PlayerShip* >( colided_with )) {
        if (Hurt_Player) {
            good_guy->DamageShip(this->GetDamage());
        }
    }
    if ( ExplosionPartical* own_kind = dynamic_cast< ExplosionPartical* >( colided_with )) {
        ExplosionPartical::SetDead(false);
    }else{
        ExplosionPartical::SetDead(true);
    }
}
