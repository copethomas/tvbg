#include "SpawnEngine.hpp"
#include "EnemyShip.hpp"

SpawnEngine::SpawnEngine(JAMCT_Logger *in_Logger, World* gameWorld,PlayerShip *in_thePlayer)
{
    SpawnEngine::theWorld = gameWorld;
    SpawnEngine::Logger = in_Logger;
    Logger->Log(JAMCT_Logger::INFO,"SpawnEngine","SpawnEngine Stating...");
    SpawnEngine::thePlayer = in_thePlayer;
    std::thread spawnThreadLauncher (&SpawnEngine::SpawnThread,this);
    std::swap(spawnThreadLauncher, SpawnEngine::Spawn);
}

void SpawnEngine::SetPause(bool is_pause)
{
    if (SpawnEngine::Pause != is_pause) {
        if (is_pause) {
            Logger->Log(JAMCT_Logger::INFO,"SpawnEngine","Sleeping...");
        }else{
            Logger->Log(JAMCT_Logger::INFO,"SpawnEngine","Awake...");
        }
    }
    SpawnEngine::Pause = is_pause;
}


void SpawnEngine::Shutdown()
{
    Logger->Log(JAMCT_Logger::INFO,"SpawnEngine","SpawnEngine Shutting Down...");
    SpawnEngine::KeepGoing = false;
    SpawnEngine::Pause = false;
    SpawnEngine::Spawn.join();
    Logger->Log(JAMCT_Logger::INFO,"SpawnEngine","SpawnEngine Dead");
}

void SpawnEngine::SpawnThread()
{
    while (SpawnEngine::KeepGoing) {
        while (SpawnEngine::Pause) {
            std::chrono::milliseconds dura(1000);
            std::this_thread::sleep_for( dura );
        }
        //Update Level with the Score.
        if ( theWorld->GetScore() > (Level * SCORE_PER_LEVEL)  ) {
            SpawnEngine::Level++;
            SpawnEngine::SpawnDelay -= 10;
            Logger->Log(JAMCT_Logger::INFO,"SpawnEngine","Reached Level " + std::to_string(Level) + " Spawn Delay = " + std::to_string(SpawnDelay));
        }
        //Delay
        std::chrono::milliseconds dura(SpawnDelay);
        std::this_thread::sleep_for( dura );
        EnemyShip *pinkguy = new EnemyShip(Logger,10,10,10,theWorld,thePlayer);
        switch (SpawnEngine::Level) {
            case 1:
                theWorld->AddEntity(pinkguy);
                break;
            case 2:
                theWorld->AddEntity(pinkguy);
                break;
            case 3:
                theWorld->AddEntity(pinkguy);
                break;
        }
    }
}