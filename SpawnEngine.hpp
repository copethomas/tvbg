#ifndef SPAWNENGINE_HPP_INCLUDED
#define SPAWNENGINE_HPP_INCLUDED
#include "World.hpp"
#include "PlayerShip.hpp"
#include <thread>
class SpawnEngine {

private:
    int Level = 1;
    bool KeepGoing = true;;
    bool Pause = true;
    std::thread Spawn;
    World *theWorld;
    void SpawnThread();
    JAMCT_Logger *Logger;
    PlayerShip *thePlayer;
    const int SCORE_PER_LEVEL = 200;
    int SpawnDelay = 2000;

public:
    SpawnEngine(JAMCT_Logger *in_Logger, World *gameWorld,PlayerShip *in_thePlayer);
    void Shutdown();
    void SetPause(bool is_pause);

};
#endif // SPAWNENGINE_HPP_INCLUDED
