#include "EnemyShip.hpp"
#include "PlayerShip.hpp"
#include "Explosion.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

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


int EnemyShip::GetTrackingDirection() {
    //Re-Write AI. - Needs to Retun the Direction We need togo. Up|Down|Left|Right
    //What ever Directoion is Greatest Away from the Player go That Way.


    //Try each Method
    //If the Method is going away from the player skip it.
    //Work out How Many Steps that method takes untill the X or Y is met. If the Answer is 0 then skip it becuase your on the same X or Y
    //If the method is taking longer than the shortest so far skip it.
    //Work out the Smallest steps out of the methoids and use that one.
}


int EnemyShip::GetEntranceDirection()
{
    if (XLocation == -40) { //If on the left
        return 90;//Go Right
    }
    if (XLocation == (theWorld->GetScreenWidth()+40)) { //If on the Right
        return 270;//Go Left
    }
    if (YLocation == -40) { //If on the Bottom
        return 0;//Go Up
    }
    if (YLocation == (theWorld->GetScreenHeight()+40)) { //If on the Top
        return 180;//Go Down
    }
}


bool EnemyShip::DefaultMove(){
    //Have we moved in further enough to Activate the AI?
    if (!AIActive) {
        if ((theWorld->EqualsBoundCheck(XLocation,AIActiveXLoc,50)) || (theWorld->EqualsBoundCheck(YLocation,AIActiveYLoc,50))) {
            AIActive = true;
        }
    }
    if (AIActive) {
        Direction = GetTrackingDirection();
    }
   MoveUp();
}

bool EnemyShip::Shoot()
{

}
void EnemyShip::Colision(Entity* colided_with)
{
    std::string colided_with_name = std::string(typeid(*colided_with).name());
    if (  colided_with_name.compare("12BulletEntity") == 0  ) {
       EnemyShip::DamageShip(colided_with->GetDamage());
       Explosion *bang = new Explosion(Logger,XLocation,YLocation,8,8,false,true,theWorld);
       theWorld->AddEntity(bang);
       theWorld->AddPoints(100);
    }

    if( PlayerShip* good_guy = dynamic_cast< PlayerShip* >( colided_with )) {
            good_guy->DamageShip(this->GetDamage());
    }

}

EnemyShip::EnemyShip(JAMCT_Logger* in_logger, int startx, int starty, int in_health, World *home_world, PlayerShip *thePlayer): Ship(in_logger,startx,starty,in_health,home_world)
{
    Direction = 0; //Pointing Forwards.
    Speed = 4; //Sort of Fast Ship
    trackingPlayer = thePlayer;
    Height = 30;
    Width = 30;
    Health = 1;
    Damage = 100;
    EnemyShip::Direction = GetEntranceDirection();
    EnemyShip::AIActiveYLoc = theWorld->RandomNumber(theWorld->GetScreenHeight(),100);
    EnemyShip::AIActiveXLoc = theWorld->RandomNumber(theWorld->GetScreenWidth(),100);

}
