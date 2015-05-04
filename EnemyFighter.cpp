#include "EnemyFighter.hpp"
#include "DrawUtil.hpp"
#include "EnemyFighterBullet.hpp"

bool EnemyFighter::Draw()
{
    DrawUtil_DrawTraingle(XLocation,YLocation,Height,Width,0,1,1,Direction);
    return true;
}

bool EnemyFighter::DefaultMove()
{
    EnemyShip::DefaultMove();
    KeyCoolDown();
    if (theWorld->EqualsBoundCheck(XLocation,trackingPlayer->GetXLocation(),5) || theWorld->EqualsBoundCheck(YLocation,trackingPlayer->GetYLocation(),5)){
        if (KeyPress == 0){
            EnemyFighter::Shoot();
        }
    }
}

bool EnemyFighter::Shoot()
{
    EnemyFighterBullet *shootnow = new EnemyFighterBullet(Logger,XLocation,YLocation,Direction);
    theWorld->AddEntity(shootnow);
    KeyPress = CoolDown;
}

EnemyFighter::EnemyFighter(JAMCT_Logger* in_logger, int startx, int starty, int in_health, World* home_world, PlayerShip* thePlayer): EnemyShip(in_logger,startx,starty,in_health,home_world,thePlayer)
{
    EnemyFighter::Speed = 5;
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
