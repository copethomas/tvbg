#include "Entity.hpp"
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

Entity::Entity(JAMCT_Logger *in_logger,int startx, int starty): Logger(in_logger) {
    Entity::Logger->Log(JAMCT_Logger::INFO,"Entity","Entity Created");
    Entity::XLocation = startx;
    Entity::YLocation = starty;
}

Entity::~Entity(){
    Logger->Log(JAMCT_Logger::INFO,"Entity","Entity Dead");
}

bool Entity::Draw() {
    int width = 10;
    int height = 10;
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

void Entity::SetDead(bool dead)
{
    Entity::IsDead = dead;
}

