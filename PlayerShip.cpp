#include "PlayerShip.hpp"
#include <GLFW/glfw3.h>

bool PlayerShip::Draw()
{
    //Draw Player Ship. (Triangle)
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,1.0f); //Blue Player
    glVertex2f(XLocation,YLocation+(Height /2));
    glVertex2f(XLocation+(Width /2),YLocation-(Height / 2));
    glVertex2f(XLocation-(Width/2),YLocation-(Height/2));
    glEnd();
    return true;
}

bool PlayerShip::DefaultMove()
{
    Logger->Log(JAMCT_Logger::ERRO,"Player Ship","No Default Move Defined. I am controled by the Player");
    return false;
}

bool PlayerShip::MoveUp()
{
    YLocation +=Speed;
}

bool PlayerShip::MoveDown()
{
    YLocation -=Speed;
}

bool PlayerShip::MoveLeft()
{

}

bool PlayerShip::MoveRight()
{

}

bool PlayerShip::Shoot()
{

}

PlayerShip::PlayerShip(JAMCT_Logger* in_logger, int startx, int starty, int in_health, World *home_world): Ship(in_logger,startx,starty,in_health,home_world)
{
    Direction = 0; //Pointing Forwards.
    Speed = 4; //Sort of Fast Ship
}

