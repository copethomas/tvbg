#include "EnemyShip.hpp"
#include "PlayerShip.hpp"
#include <GLFW/glfw3.h>

bool EnemyShip::Draw()
{
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,1.0f); //Blue Player
    glVertex2f(XLocation, YLocation);
    glVertex2f(XLocation + Width, YLocation);
    glVertex2f(XLocation + Width, YLocation + Height);
    glVertex2f(XLocation, YLocation + Height);
    glEnd();
    return true;
}

bool EnemyShip::DefaultMove(){
    //Set Direction to the Player (Very Simple AI)
    if (theWorld->EqualsBoundCheck(trackingPlayer->GetYLocation(),YLocation,6)) {
        if (trackingPlayer->GetXLocation() > XLocation) {
            Direction = 90;
        }else{
            Direction = 270;
        }
    }
    if (theWorld->EqualsBoundCheck(trackingPlayer->GetXLocation(),XLocation,6)) {
        if (trackingPlayer->GetYLocation() > YLocation) {
            Direction = 0;
        }else{
            Direction = 180;
        }
    }
    //Move to the Player
   MoveUp();
}

bool EnemyShip::Shoot()
{

}

EnemyShip::EnemyShip(JAMCT_Logger* in_logger, int startx, int starty, int in_health, World *home_world, PlayerShip *thePlayer): Ship(in_logger,startx,starty,in_health,home_world)
{
    Direction = 0; //Pointing Forwards.
    Speed = 4; //Sort of Fast Ship
    trackingPlayer = thePlayer;
}