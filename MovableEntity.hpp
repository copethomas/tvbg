#ifndef MOVABLEENTITY_HPP_INCLUDED
#define MOVABLEENTITY_HPP_INCLUDED
#include "Entity.hpp"
#include "JAMCT_Logger.hpp"
class MovableEntity: public Entity {

protected:
    int Speed;
    int Direction = 0;

public:
    virtual bool Draw();
    virtual bool DefaultMove();
    virtual bool MoveUp();
    virtual bool MoveDown();
    virtual bool MoveLeft();
    virtual bool MoveRight();
    MovableEntity(JAMCT_Logger *in_logger,int startx,int starty);

};

#endif // MOVABLEENTITY_HPP_INCLUDED
