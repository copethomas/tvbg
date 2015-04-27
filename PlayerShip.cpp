#include "PlayerShip.hpp"
#include <GLFW/glfw3.h>
#include "BulletEntity.hpp"
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
        glVertex2f(XLocation+(Width/2),YLocation+(Height/2));
        glVertex2f(XLocation+(Width/2),YLocation-(Height/2));
        glVertex2f(XLocation-(Width/2),YLocation+(Height/2));
        break;
    case 90:
        glVertex2f(XLocation-(Width/2),YLocation+(Height/2));
        glVertex2f(XLocation+(Width/2),YLocation);
        glVertex2f(XLocation-(Width/2),YLocation-(Height/2));
        break;
    case 135:
        glVertex2f(XLocation+(Width/2),YLocation-(Height/2));
        glVertex2f(XLocation-(Width/2),YLocation-(Height/2));
        glVertex2f(XLocation+(Width/2),YLocation+(Height/2));
        break;
    case 180:
        glVertex2f(XLocation,YLocation-(Height /2));
        glVertex2f(XLocation-(Width /2),YLocation+(Height / 2));
        glVertex2f(XLocation+(Width/2),YLocation+(Height/2));
        break;
    case 225:
        glVertex2f(XLocation-(Width/2),YLocation-(Height/2));
        glVertex2f(XLocation-(Width/2),YLocation+(Height/2));
        glVertex2f(XLocation+(Width/2),YLocation-(Height/2));
        break;
    case 270:
        glVertex2f(XLocation+(Width/2),YLocation-(Height/2));
        glVertex2f(XLocation-(Width/2),YLocation);
        glVertex2f(XLocation+(Width/2),YLocation+(Height/2));
        break;
    case 315:
        glVertex2f(XLocation-(Width/2),YLocation+(Height/2));
        glVertex2f(XLocation+(Width/2),YLocation+(Height/2));
        glVertex2f(XLocation-(Width/2),YLocation-(Height/2));
        break;
    }
    glEnd();
    return true;
}

bool PlayerShip::DefaultMove()
{
    return false;
}

bool PlayerShip::Shoot()
{
    if (KeyPress == 0)
    {
        BulletEntity *test = new BulletEntity(Logger,XLocation,YLocation,Direction);
        theWorld->AddEntity(test);
        KeyPress = CoolDown;
    }
    return true;
}

PlayerShip::PlayerShip(JAMCT_Logger* in_logger, int startx, int starty, int in_health, World *home_world): Ship(in_logger,startx,starty,in_health,home_world)
{
    Direction = 0; //Pointing Forwards.
    Speed = 4; //Sort of Fast Ship
}

void PlayerShip::WKey(bool keyState)
{
    if (keyState)
    {
        YLocation+=Speed;
        if (Keys[Key_Name::A] == false & Keys[Key_Name::D] == false)
        {
            Direction = 0;
        }
        Keys[Key_Name::W] = true;
    }
    else
    {
        Keys[Key_Name::W] = false;
    }
}

void PlayerShip::AKey(bool keyState)
{
    if (keyState)
    {
        XLocation-=Speed;
        Direction = 270;
        if (Keys[Key_Name::W] == true)
        {
            Direction = 315;
        }
        if (Keys[Key_Name::S] == true)
        {
            Direction = 225;
        }
        Keys[Key_Name::A] = true;
    }
    else
    {
        Keys[Key_Name::A] = false;
    }
}

void PlayerShip::SKey(bool keyState)
{
    if (keyState)
    {
        YLocation-=Speed;
        if (Keys[Key_Name::A] == false & Keys[Key_Name::D] == false)
        {
            Direction = 180;
        }
        Keys[Key_Name::S] = true;
    }
    else
    {
        Keys[Key_Name::S] = false;
    }
}

void PlayerShip::DKey(bool keyState)
{
    if (keyState)
    {
        XLocation+=Speed;
        Direction = 90;
        if (Keys[Key_Name::W] == true)
        {
            Direction = 45;
        }
        if (Keys[Key_Name::S] == true)
        {
            Direction = 135;
        }
        Keys[Key_Name::D] = true;
    }
    else
    {
        Keys[Key_Name::D] = false;
    }
}



