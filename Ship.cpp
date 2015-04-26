#include "Ship.hpp"
bool Ship::Draw()
{
    return true;
}

bool Ship::DefaultMove()
{
    return true;
}

bool Ship::MoveUp()
{
    return true;
}

bool Ship::MoveDown()
{
    return true;
}

bool Ship::MoveLeft()
{
    return true;
}

bool Ship::MoveRight()
{
    return true;
}

void Ship::DamageShip(int hitDamage)
{
    Ship::Health =- hitDamage;
}

bool Ship::Shoot()
{
    return true;
}


Ship::Ship(JAMCT_Logger* in_logger, int startx, int starty, int in_health,World *home_world): MovableEntity(in_logger,startx,starty)
{
    Ship::Health = in_health;
    Ship::theWorld = home_world;
}


