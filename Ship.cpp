#include "Ship.hpp"
#include <GLFW/glfw3.h>

bool Ship::Draw()
{
    int width = 40;
    int height = 40;
    int x = Entity::XLocation;
    int y = Entity::YLocation;
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
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

Ship::Ship(JAMCT_Logger* in_logger, int startx, int starty, int shipHealth)
{
    Ship::Logger = in_logger;
    Ship::XLocation = startx;
    Ship::YLocation = starty;
    Ship::Health = shipHealth;
}
