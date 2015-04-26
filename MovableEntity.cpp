#include "MovableEntity.hpp"
#include "Entity.hpp"

bool MovableEntity::Draw() {
    return true;
}

bool MovableEntity::DefaultMove()
{
    return true;
}

bool MovableEntity::MoveUp()
{
   switch(Direction)
    {
    case 0:
        YLocation +=Speed;
        break;
    case 45:
        XLocation +=Speed;
        YLocation +=Speed;
        break;
    case 90:
        XLocation +=Speed;
        break;
    case 135:
        YLocation -=Speed;
        XLocation +=Speed;
        break;
    case 180:
        YLocation -=Speed;
        break;
    case 225:
        YLocation -=Speed;
        XLocation -=Speed;
        break;
    case 270:
        XLocation -=Speed;
        break;
    case 315:
        YLocation +=Speed;
        XLocation -=Speed;
        break;
    }
    return true;
}

bool MovableEntity::MoveDown()
{
switch(Direction)
    {
    case 0:
        YLocation -=Speed;
        break;
    case 45:
        XLocation -=Speed;
        YLocation -=Speed;
        break;
    case 90:
        XLocation -=Speed;
        break;
    case 135:
        YLocation +=Speed;
        XLocation -=Speed;
        break;
    case 180:
        YLocation +=Speed;
        break;
    case 225:
        YLocation +=Speed;
        XLocation +=Speed;
        break;
    case 270:
        XLocation +=Speed;
        break;
    case 315:
        YLocation -=Speed;
        XLocation +=Speed;
        break;
    }
    return true;
    return true;
}

bool MovableEntity::MoveLeft()
{
if (KeyPress == 0)
    {
        Direction -= 45;
        if (Direction < 0)
        {
            Direction = 315;
        }
        KeyPress = CoolDown;
    }
    return true;
}

bool MovableEntity::MoveRight()
{
    if (KeyPress == 0)
    {
        Direction += 45;
        if (Direction > 315)
        {
            Direction = 0;
        }
        KeyPress = CoolDown;
    }
    return true;
}

MovableEntity::MovableEntity(JAMCT_Logger* in_logger, int startx, int starty): Entity(in_logger,startx,starty)
{
    //Nothing Else to Construct
}
void MovableEntity::KeyCoolDown()
{
     if (KeyPress!=0)
    {
        KeyPress -=1;
    }
}




