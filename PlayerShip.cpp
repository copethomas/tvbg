#include "PlayerShip.hpp"
#include <GLFW/glfw3.h>

bool PlayerShip::Draw()
{
    //Draw Player Ship. (Triangle)
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,1.0f); //Blue Player
    switch(Direction)
    {
    case 0:
        glVertex2f(XLocation,YLocation+(Height /2));
        glVertex2f(XLocation+(Width /2),YLocation-(Height / 2));
        glVertex2f(XLocation-(Width/2),YLocation-(Height/2));
        break;
    case 45:
        glVertex2f(XLocation+(Width/3), YLocation + (Height/3));

        glVertex2f(XLocation,YLocation - (Height/3));

        glVertex2f(XLocation-(Width/3), YLocation + (Height/3));





        break;
    case 90:
        glVertex2f(XLocation-(Width/2),YLocation+(Height/2));
        glVertex2f(XLocation + (Width/2),YLocation);
        glVertex2f(XLocation - (Width/2),YLocation-(Height/2));
        break;
    case 135:

        break;
    case 180:
        glVertex2f(XLocation,YLocation-(Height /2));
        glVertex2f(XLocation-(Width /2),YLocation+(Height / 2));
        glVertex2f(XLocation+(Width/2),YLocation+(Height/2));
        break;
    case 225:

        break;
    case 270:
        glVertex2f(XLocation+(Width/2),YLocation-(Height/2));
        glVertex2f(XLocation - (Width/2),YLocation);
        glVertex2f(XLocation + (Width/2),YLocation+(Height/2));
        break;
    case 315:

        break;
    }
    glEnd();
    return true;
}

bool PlayerShip::DefaultMove()
{
    Logger->Log(JAMCT_Logger::ERRO,"Player Ship","No Default Move Defined. I am controled by the Player");
    return false;
}

bool PlayerShip::Shoot()
{
    Logger->Log(JAMCT_Logger::INFO,"Player Ship","Current Direction: " + std::to_string(Direction));
}

PlayerShip::PlayerShip(JAMCT_Logger* in_logger, int startx, int starty, int in_health, World *home_world): Ship(in_logger,startx,starty,in_health,home_world)
{
    Direction = 0; //Pointing Forwards.
    Speed = 4; //Sort of Fast Ship
}

