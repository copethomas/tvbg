#include "PlayerDeathPartical.hpp"
#include <GLFW/glfw3.h>
bool PlayerDeathPartical::Draw()
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,1.0f); //Blue Player
    switch(PlayerDeathPartical::SpinDirection)
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

bool PlayerDeathPartical::DefaultMove()
{
    MoveUp();
    PlayerDeathPartical::SpinDirection += 45;
    if (PlayerDeathPartical::SpinDirection > 315) {
        SpinDirection = 0;
    }
}

PlayerDeathPartical::PlayerDeathPartical(JAMCT_Logger* in_logger, int startx, int starty, int heading_direction,int speed): BulletEntity(in_logger,startx,starty,heading_direction)
{
    PlayerDeathPartical::Height = 10;
    PlayerDeathPartical::Width = 10;
    PlayerDeathPartical::Speed = speed;
    PlayerDeathPartical::Damage = 0;
}

void PlayerDeathPartical::Colision(Entity* colided_with)
{
    //DO nothing. I don't collide with anything.
}

