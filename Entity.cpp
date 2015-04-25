#include "Entity.hpp"
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

Entity::Entity(JAMCT_Logger *in_logger): Logger(in_logger) {
    Logger->Log(JAMCT_Logger::INFO,"Entity","Entity Created");
}

Entity::~Entity(){
    Logger->Log(JAMCT_Logger::INFO,"Entity","Entity Dead");
}

bool Entity::Draw() {
    glBegin(GL_QUADS);
    glVertex2f(10, 10);
    glVertex2f(10 + 10, 10);
    glVertex2f(10 + 10, 10 + 10);
    glVertex2f(10, 10 + 10);
    glEnd();
    return true;
}

void Entity::SetDead(bool dead)
{
    Entity::IsDead = dead;
}

