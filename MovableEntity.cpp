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
    return true;
}

bool MovableEntity::MoveDown()
{
    return true;
}

bool MovableEntity::MoveLeft()
{
    return true;
}

bool MovableEntity::MoveRight()
{
    return true;
}

MovableEntity::MovableEntity(JAMCT_Logger* in_logger, int startx, int starty): Entity(in_logger,startx,starty)
{
    //Nothing Else to Construct
}


