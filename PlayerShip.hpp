#ifndef PLAYERSHIP_HPP_INCLUDED
#define PLAYERSHIP_HPP_INCLUDED
#include "Ship.hpp"
class PlayerShip: public Ship {

private:
    bool Keys[4] = {false,false,false,false};
    enum Key_Name {W,A,S,D};

public:
    virtual bool Draw();
    virtual bool DefaultMove();
    virtual bool Shoot();
    PlayerShip(JAMCT_Logger *in_logger,int startx,int starty,int in_health,World *home_world);
    void WKey(bool keyState);
    void AKey(bool keyState);
    void SKey(bool keyState);
    void DKey(bool keyState);
    void DebugKey(bool keyState);


};
#endif // PLAYERSHIP_HPP_INCLUDED
