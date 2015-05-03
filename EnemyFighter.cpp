#include "EnemyFighter.hpp"

bool EnemyFighter::Draw()
{
   //Draw Player Ship. (Triangle)
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,1.0f,1.0f); //Blue Player
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

bool EnemyFighter::DefaultMove()
{
   // EnemyShip::DefaultMove();
}

bool EnemyFighter::Shoot()
{

}

EnemyFighter::EnemyFighter(JAMCT_Logger* in_logger, int startx, int starty, int in_health, World* home_world, PlayerShip* thePlayer): EnemyShip(in_logger,startx,starty,in_health,home_world,thePlayer)
{
    EnemyFighter::Speed = 6;
    EnemyFighter::Height = 40;
    EnemyFighter::Width  = 40;
    EnemyFighter::Direction = 0;
}

void EnemyFighter::Colision(Entity* colided_with)
{
    EnemyShip::Colision(colided_with);//Same Colision as above but with more points.
    std::string colided_with_name = std::string(typeid(*colided_with).name());
    if (  colided_with_name.compare("12BulletEntity") == 0  ) {
        theWorld->AddPoints(50); //50 extra points.
    }
}
