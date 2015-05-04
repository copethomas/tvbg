#include "PlayerDeathPartical.hpp"
#include "DrawUtil.hpp"
#include <GLFW/glfw3.h>
bool PlayerDeathPartical::Draw()
{
    DrawUtil_DrawTraingle(XLocation,YLocation,Height,Width,0,0,1,SpinDirection);
    PlayerDeathPartical::SpinDirection +=45;
    if (PlayerDeathPartical::SpinDirection > 315) {
        PlayerDeathPartical::SpinDirection = 0;
    }
    return true;
}

bool PlayerDeathPartical::DefaultMove()
{
    MoveUp();
    PlayerDeathPartical::SpinDirection += 45;
    if (PlayerDeathPartical::SpinDirection > 315) {
        SpinDirection = 0;
    }
}

PlayerDeathPartical::PlayerDeathPartical(JAMCT_Logger* in_logger, int startx, int starty, int heading_direction,int speed): BulletEntity(in_logger,startx,starty,heading_direction)
{
    PlayerDeathPartical::Height = 10;
    PlayerDeathPartical::Width = 10;
    PlayerDeathPartical::Speed = speed;
    PlayerDeathPartical::Damage = 0;
}

void PlayerDeathPartical::Colision(Entity* colided_with)
{
    //DO nothing. I don't collide with anything.
}

