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
    int SpawnDelay = 5000;
    int GetSpawnLoc(bool ReturnX, int SpawnSide);

public:
    SpawnEngine(JAMCT_Logger *in_Logger, World *gameWorld,PlayerShip *in_thePlayer);
    void Shutdown();
    void SetPause(bool is_pause);
    void SetLevel(int newlevel);

};
#endif // SPAWNENGINE_HPP_INCLUDED
