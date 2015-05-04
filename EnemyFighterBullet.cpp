#include "EnemyFighterBullet.hpp"
#include "DrawUtil.hpp"
#include "PlayerShip.hpp"

EnemyFighterBullet::EnemyFighterBullet(JAMCT_Logger* in_logger, int startx, int starty, int heading_direction): BulletEntity(in_logger,startx,starty,heading_direction)
{
    Speed = 10;
    Width = 6;
    Height = 6;
    Health = 1;
    Damage = 5;
}

void EnemyFighterBullet::Colision(Entity* colided_with)
{
    if( PlayerShip* good_guy = dynamic_cast< PlayerShip* >( colided_with ))
    {
        good_guy->DamageShip(this->GetDamage());
    }
}

bool EnemyFighterBullet::Draw()
{
    switch (Colour_Modifier)
    {
    case 1:
        DrawUtil_DrawSquare(XLocation,YLocation,Height,Width,1,0,0);
        break;
    case 2:
        DrawUtil_DrawSquare(XLocation,YLocation,Height,Width,0,1,0);
        break;
    case 3:
        DrawUtil_DrawSquare(XLocation,YLocation,Height,Width,0,0,1);
        break;
    }
    Colour_Modifier+=1;
    if (Colour_Modifier==4)
    {
        Colour_Modifier=1;
    }
    return true;
}
