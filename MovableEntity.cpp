#include "MovableEntity.hpp"
#include "Entity.hpp"
#include <GLFW/glfw3.h>

bool MovableEntity::Draw() {
    int width = 30;
    int height = 30;
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
