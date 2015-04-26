#include "Entity.hpp"
#include <string>
#include <iostream>

Entity::Entity(JAMCT_Logger *in_logger,int startx, int starty): Logger(in_logger) {
   // Entity::Logger->Log(JAMCT_Logger::INFO,"Entity","Entity Created");
    Entity::XLocation = startx;
    Entity::YLocation = starty;
}

Entity::~Entity(){
   // Logger->Log(JAMCT_Logger::INFO,"Entity","Entity Dead");
}

bool Entity::Draw() {
    return true;
}

void Entity::SetDead(bool dead)
{
    Entity::IsDead = dead;
}
int Entity::GetXLocation()
{
    return Entity::XLocation;
}

int Entity::GetYLocation()
{
    return Entity::YLocation;
}
bool Entity::GetDead()
{
    return IsDead;
}



