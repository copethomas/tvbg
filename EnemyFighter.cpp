#include "EnemyFighter.hpp"
#include "DrawUtil.hpp"

bool EnemyFighter::Draw()
{
    DrawUtil_DrawTraingle(XLocation,YLocation,Height,Width,0,1,1,Direction);
    return true;
}

bool EnemyFighter::DefaultMove()
{
    EnemyShip::DefaultMove();
}

bool EnemyFighter::Shoot()
{

}

EnemyFighter::EnemyFighter(JAMCT_Logger* in_logger, int startx, int starty, int in_health, World* home_world, PlayerShip* thePlayer): EnemyShip(in_logger,startx,starty,in_health,home_world,thePlayer)
{
    EnemyFighter::Speed = 8;
    EnemyFighter::Height = 40;
    EnemyFighter::Width  = 40;
}

void EnemyFighter::Colision(Entity* colided_with)
{
    EnemyShip::Colision(colided_with);//Same Colision as above but with more points.
    std::string colided_with_name = std::string(typeid(*colided_with).name());
    if (  colided_with_name.compare("12BulletEntity") == 0  ) {
        theWorld->AddPoints(50); //50 extra points.
    }
}
