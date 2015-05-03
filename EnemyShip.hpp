#ifndef ENEMYSHIP_HPP_INCLUDED
#define ENEMYSHIP_HPP_INCLUDED
#include "PlayerShip.hpp"
class EnemyShip: public Ship {

private:
    PlayerShip *trackingPlayer;
    bool AIActive = false;
    int AIActiveXLoc = 0;
    int AIActiveYLoc = 0;
    int GetTrackingDirection();
    int GetEntranceDirection();
    enum MOVEMENT_TYPES {UP,DOWN,LEFT,RIGHT,UP_LEFT,UP_RIGHT,DOWN_LEFT,DOWN_RIGHT};
    int MOVEMENT_TYPES_DIR[8] = {0,180,270,90,45,315,135,225};
    int BestMethod = 0;
    int BestXImprov = 0;
    int BestYImprov = 0;

public:
    virtual bool Draw();
    virtual bool DefaultMove();
    virtual bool Shoot();
    EnemyShip(JAMCT_Logger *in_logger,int startx,int starty,int in_health,World *home_world,PlayerShip *thePlayer);
    virtual void Colision(Entity *colided_with);
};


#endif // ENEMYSHIP_HPP_INCLUDED
