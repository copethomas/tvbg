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
    glBegin(GL_TRIANGLES);
    glColor3f(1.f,0.f,0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();
    return true;
}

void Entity::SetDead(bool dead)
{
    Entity::IsDead = dead;
}

