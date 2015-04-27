#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED
#include "JAMCT_Logger.hpp"
class Entity{

protected:
    int XLocation = 0;
    int YLocation = 0;
    int Height = 1;
    int Width = 1;
    bool IsDead = false;
    JAMCT_Logger *Logger;

public:
    virtual bool Draw();
    void SetDead(bool dead);
    Entity(JAMCT_Logger *in_logger,int startx,int starty);
    virtual ~Entity();
    int GetXLocation();
    int GetYLocation();
    bool GetDead();
};


#endif // ENTITY_HPP_INCLUDED
