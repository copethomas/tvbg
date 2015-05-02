#ifndef SPAWNENGINE_HPP_INCLUDED
#define SPAWNENGINE_HPP_INCLUDED
#include "World.hpp"
#include "PlayerShip.hpp"
#include <thread>
class SpawnEngine {

private:
    int Level;
    bool KeepGoing = true;;
    bool Pause = true;
    std::thread Spawn;
    World *theWorld;
    void SpawnThread();
    JAMCT_Logger *Logger;
    PlayerShip *thePlayer;

public:
    SpawnEngine(JAMCT_Logger *in_Logger, World *gameWorld,PlayerShip *in_thePlayer);
    void Shutdown();
    void SetPause(bool is_pause);

};
#endif // SPAWNENGINE_HPP_INCLUDED
