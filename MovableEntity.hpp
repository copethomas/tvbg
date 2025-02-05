#ifndef MOVABLEENTITY_HPP_INCLUDED
#define MOVABLEENTITY_HPP_INCLUDED
#include "Entity.hpp"
#include "JAMCT_Logger.hpp"
class MovableEntity: public Entity {

protected:
    int Speed;
    int Direction = 0;
    int KeyPress = 0;
    const int CoolDown = 10;

public:
    virtual bool Draw();
    virtual bool DefaultMove();
    bool MoveUp();
    bool MoveDown();
    bool MoveLeft();
    bool MoveRight();
    void KeyCoolDown();
    int GetSpeed();
    MovableEntity(JAMCT_Logger *in_logger,int startx,int starty);

};

#endif // MOVABLEENTITY_HPP_INCLUDED
