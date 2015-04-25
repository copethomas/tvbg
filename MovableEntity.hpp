#ifndef MOVABLEENTITY_HPP_INCLUDED
#define MOVABLEENTITY_HPP_INCLUDED
#include "Entity.hpp"
class MovableEntity: public Entity {

using Entity::Entity;

private:
    int Speed;
    int Direction;

public:
    virtual bool Draw();
    virtual bool DefaultMove();
    virtual bool MoveUp();
    virtual bool MoveDown();
    virtual bool MoveLeft();
    virtual bool MoveRight();
};

#endif // MOVABLEENTITY_HPP_INCLUDED
