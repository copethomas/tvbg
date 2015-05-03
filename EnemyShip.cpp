#include "EnemyShip.hpp"
#include "PlayerShip.hpp"
#include "Explosion.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

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

bool ClosedGap(int point_old, int point_new, int point_ref) {
    if (point_ref < point_old){
        if ((point_old - point_ref)>(point_new-point_ref)){
            return true;
        }else{
            return false;
        }
    }else{
        if ((point_ref-point_old)>(point_ref-point_new)){
            return true;
        }else{
            return false;
        }
    }
    return false;
}

int EnemyShip::GetAIX()
{
    if (XLocation > trackingPlayer->GetXLocation())
    {
        return 270;
    }
    else
    {
        return 90;
    }
}

int EnemyShip::GetAIY()
{
    if (YLocation > trackingPlayer->GetYLocation())
    {
        //Y Is Larger needs to be smaller.
        return 180;
    }
    else
    {
        return 0;
    }

}

int EnemyShip::GetTrackingDirection()
{
    //IF X is more important
    if (theWorld->EqualsBoundCheck(XLocation,trackingPlayer->GetXLocation(),(Speed/2)))
    {
        //XLocation is Matched need to find Y
        return GetAIY();
    }
    else
    {
        return GetAIX();
    }
    //IF Y is more Important
    if (theWorld->EqualsBoundCheck(YLocation,trackingPlayer->GetYLocation(),(Speed/2)))
    {
        //YLocation Is Matchd need to findX
        return GetAIX();
    }
    else
    {
        return GetAIY();
    }
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
