#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED
#include "JAMCT_Logger.hpp"
class Entity{

private:
    int XLocation = 0;
    int YLocation = 0;
    bool IsDead = false;
    JAMCT_Logger *Logger;

public:
    bool Draw();
    void SetDead(bool dead);
    Entity(JAMCT_Logger *in_logger);
    ~Entity();
};


#endif // ENTITY_HPP_INCLUDED
