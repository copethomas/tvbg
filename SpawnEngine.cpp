#include "SpawnEngine.hpp"
#include "EnemyShip.hpp"
#include "EnemyFighter.hpp"
#include "Message.hpp"

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
    try{
        SpawnEngine::Spawn.join();
    }catch(std::exception& errorMessage) {
        Logger->Log(JAMCT_Logger::INFO,"SpawnEngine","Tried to join to dead thread. Skipping...");
    }
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
        if ( theWorld->GetScore() > ((Level * SCORE_PER_LEVEL) + (Level * SCORE_PER_LEVEL))) {
            SpawnEngine::Level++;
            Message *levelup = new Message(Logger,(theWorld->GetScreenWidth()/2),(10),50,"Level " + std::to_string(Level),1500);
            theWorld->AddEntity(levelup);
            if (SpawnDelay > 20) {
                SpawnEngine::SpawnDelay -= 50;
            }else{
                Logger->Log(JAMCT_Logger::INFO,"SpawnEngine","Spawn Delay Maxed out! Will not go lower than: " + std::to_string(SpawnDelay));
            }
            Logger->Log(JAMCT_Logger::INFO,"SpawnEngine","Reached Level " + std::to_string(Level) + " Spawn Delay = " + std::to_string(SpawnDelay));
        }
        //Delay
        std::chrono::milliseconds dura(SpawnDelay);
        std::this_thread::sleep_for( dura );
        //SpawnSide
        for (int i=1; i<(Level + 3);i++) {
        int SpawnX = 0;
        int SpawnY = 0;
        switch(theWorld->RandomNumber(4,1)) {
            case 1://Left
                SpawnX = -40;
                SpawnY = theWorld->RandomNumber(theWorld->GetScreenHeight(),20);
            break;

            case 2://Right
                SpawnX = theWorld->GetScreenWidth() + 40;
                SpawnY = theWorld->RandomNumber(theWorld->GetScreenHeight(),20);
            break;

            case 3://Top
                SpawnX = theWorld->RandomNumber(theWorld->GetScreenWidth(),20);
                SpawnY = theWorld->GetScreenHeight() + 40;
            break;

            case 4://Bottom
                SpawnX = theWorld->RandomNumber(theWorld->GetScreenWidth(),20);
                SpawnY = -40;
            break;
        }
        if (Level > 0) {
            EnemyShip *pinkguy = new EnemyShip(Logger,SpawnX,SpawnY,10,theWorld,thePlayer);
            theWorld->AddEntity(pinkguy);
        }
        if (Level > 3) {
            EnemyFighter *fighter = new EnemyFighter(Logger,SpawnX,SpawnY,10,theWorld,thePlayer);
            theWorld->AddEntity(fighter);
        }
       }
    }
}

void SpawnEngine::SetLevel(int newlevel)
{
    SpawnEngine::Level = newlevel;
}

