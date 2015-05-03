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

int GapAmmount(int point_old, int point_new, int point_ref) {
    if ((point_old > point_ref) && (point_new > point_ref)) {
        return (point_old - point_new);
    }
    if ((point_old < point_ref) && (point_new < point_ref)) {
        return (point_old - point_new);
    }
    return -1;
}

int EnemyShip::GetTrackingDirection() {
    //Re-Write AI. - Needs to Retun the Direction We need togo. Up|Down|Left|Right
    //Try each Method
    //If the Method is going away from the player skip it.
    //Work out How Many Steps that method takes untill the X or Y is met. If the Answer is 0 then skip it becuase your on the same X or Y
    //If the method is taking longer than the shortest so far skip it.
    //Work out the Smallest steps out of the methoids and use that one.
    int ThearyX, ThearyY, Before_ThearyX, Before_ThearyY, CurrentMethod;
    bool improved = false;
    for (int i=0;i<8;i++) {
        CurrentMethod = i;
        ThearyX = XLocation;
        Before_ThearyX = XLocation;
        ThearyY = YLocation;
        Before_ThearyY = YLocation;
        improved = false;
        do{ //Run through each method untill they stop being usefull
            switch (i) {
            case UP:
                ThearyY++;
            break;
            case DOWN:
                ThearyY--;
            break;
            case LEFT:
                ThearyX--;
            break;
            case RIGHT:
                ThearyX++;
            break;
            case UP_LEFT:
                ThearyY++;
                ThearyX--;
            break;
            case UP_RIGHT:
                ThearyY++;
                ThearyX++;
            break;
            case DOWN_LEFT:
                ThearyY--;
                ThearyX--;
            break;
            case DOWN_RIGHT:
                ThearyY--;
                ThearyX++;
            break;
            }
        //Right That method has stoped being usefull.
        //How did it do?
        int XImprove,YImprove;
        XImprove = GapAmmount(Before_ThearyX,ThearyX,trackingPlayer->GetXLocation());
        YImprove = GapAmmount(Before_ThearyY,ThearyY,trackingPlayer->GetYLocation());
        if ((XImprove > 0) || (YImprove > 0)) {
        //Right so We made some progress. Yay!
        if ( (XImprove > BestXImprov) || (YImprove > BestYImprov)) {
            BestMethod = CurrentMethod;
            improved = true;
        }else{
            improved = false;
        }
        }else{
            improved = false;
        }
            }while (improved);//check goes here
    }
    return (BestMethod * 45);
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
