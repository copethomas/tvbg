#include "PlayerShip.hpp"
#include <GLFW/glfw3.h>
#include "BulletEntity.hpp"
#include "EnemyFighter.hpp"
#include "Explosion.hpp"
#include "DrawUtil.hpp"
bool PlayerShip::Draw()
{
    if (PlayerShip::Hidden) {
        return true;
    }
    DrawUtil_DrawTraingle(XLocation,YLocation,Height,Width,0,0,1,Direction);
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
void PlayerShip::DebugKey(bool keyState)
{
    if (KeyPress == 0 && (keyState == true))
    {
        //EnemyShip *test = new EnemyShip(Logger,600,600,1,theWorld,this);
        //ExplosionPartical *test = new ExplosionPartical(Logger,50,50,0,100,false,false);
        //Explosion *test = new Explosion(Logger,50,50,8,10,false,false,theWorld);
        //EnemyFighter *test = new EnemyFighter(Logger,500,500,10,theWorld,this);
        //theWorld->AddEntity(test);
        KeyPress = CoolDown;
    }
}

PlayerShip::PlayerShip(JAMCT_Logger* in_logger, int startx, int starty, int in_health, World *home_world): Ship(in_logger,startx,starty,in_health,home_world)
{
    Direction = 0; //Pointing Forwards.
    Speed = 6; //Sort of Fast Ship
    Height = 30;
    Width = 30;
}

void PlayerShip::WKey(bool keyState)
{
    if (keyState)
    {
        if (!IsOffScreenW()) {YLocation+=Speed;}
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
         if (!IsOffScreenA()) {XLocation-=Speed;}
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
        if (!IsOffScreenS()) {YLocation-=Speed;}
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
         if (!IsOffScreenD()) {XLocation+=Speed;}
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

void PlayerShip::DamageShip(int hitDamage)
{
    PlayerShip::Health =- hitDamage;
    if (Health <= 0 ) {
        if (!(PlayerShip::Hidden)) {
            theWorld->SetGameState(World::GAMEOVER);
            Logger->Log(JAMCT_Logger::AERT,"Player","Player Died. Final Score: " + std::to_string(theWorld->GetScore()));
            for (int i=0; i<theWorld->RandomNumber(15,10);i++) {
                Explosion *playerdead = new Explosion(Logger,XLocation,YLocation,theWorld->RandomNumber(12,5),100000,false,false,theWorld,theWorld->RandomNumber(10,1));
                theWorld->AddEntity(playerdead);
            }
        }
        PlayerShip::Hidden = true;
    }
}

void PlayerShip::Respawn()
{
    PlayerShip::Health = 10;
    PlayerShip::XLocation = theWorld->GetScreenWidth()/2;
    PlayerShip::YLocation = theWorld->GetScreenHeight()/2;
    PlayerShip::Hidden = false;
}

bool PlayerShip::IsOffScreenW() {
    int BOARDER = (Speed + 10);

    if (YLocation > (theWorld->GetScreenHeight() - BOARDER) ) {
        return true;
    }else{
        return false;
    }

}
bool PlayerShip::IsOffScreenA()
{
    int BOARDER = (Speed + 10);
    if (XLocation < (BOARDER)) {
        return true;
    }else{
        return false;
    }
}

bool PlayerShip::IsOffScreenS()
{
    int BOARDER = (Speed + 10);
    if (YLocation < (BOARDER)) {
        return true;
    }else{
        return false;
    }
}

bool PlayerShip::IsOffScreenD()
{
    int BOARDER = (Speed + 10);
    if (XLocation > (theWorld->GetScreenWidth() - BOARDER) ) {
        return true;
    }else{
        return false;
    }
}




