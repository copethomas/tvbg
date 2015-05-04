#include "BulletEntity.hpp"
#include "DrawUtil.hpp"

bool BulletEntity::Draw()
{
    //DrawUtil_DrawCircle(XLocation,YLocation,Width,160,1.0f,0.0f,0.0f);
    DrawUtil_DrawSquare(XLocation,YLocation,Width,Height,1,0,0);
    return true;
}

bool BulletEntity::DefaultMove()
{
    MoveUp();
}

void BulletEntity::Colision(Entity* colided_with)
{
    std::string colided_with_name = std::string(typeid(*colided_with).name());
    if (  colided_with_name.compare("9EnemyShip") == 0  ) {
       BulletEntity::SetDead(true);
    }
}


BulletEntity::BulletEntity(JAMCT_Logger* in_logger, int startx, int starty, int heading_direction): MovableEntity(in_logger,startx,starty)
{
    BulletEntity::Direction = heading_direction;
    BulletEntity::Speed = 20;
    Width = 4;
    Height = 4;
    Health = 1;
    Damage = 1;
}
