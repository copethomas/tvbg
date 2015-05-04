#include "SpawnEngine.hpp"
#include "EnemyShip.hpp"
#include "EnemyFighter.hpp"
#include "Message.hpp"
#include <math.h>

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
    if (SpawnEngine::Pause != is_pause)
    {
        if (is_pause)
        {
            Logger->Log(JAMCT_Logger::INFO,"SpawnEngine","Sleeping...");
        }
        else
        {
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
    try
    {
        SpawnEngine::Spawn.join();
    }
    catch(std::exception& errorMessage)
    {
        Logger->Log(JAMCT_Logger::INFO,"SpawnEngine","Tried to join to dead thread. Skipping...");
    }
    Logger->Log(JAMCT_Logger::INFO,"SpawnEngine","SpawnEngine Dead");
}


int SpawnEngine::GetSpawnLoc(bool ReturnX, int Side) //Returns Y by Default.
{
    int SpawnX = 0;
    int SpawnY = 0;
    switch(Side)
    {
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
    if (ReturnX) {return SpawnX;}
    return SpawnY;
}




void SpawnEngine::SpawnThread()
{
    while (SpawnEngine::KeepGoing)
    {
        while (SpawnEngine::Pause)
        {
            std::chrono::milliseconds dura(1000);
            std::this_thread::sleep_for( dura );
        }
        //Update Level with the Score.
        if ( theWorld->GetScore() > ((Level * SCORE_PER_LEVEL) + (Level * SCORE_PER_LEVEL)))
        {
            SpawnEngine::Level++;
            Message *levelup = new Message(Logger,(theWorld->GetScreenWidth()/2),(10),50,"Level " + std::to_string(Level),1500);
            theWorld->AddEntity(levelup);
            if (SpawnDelay > 20)
            {
                SpawnEngine::SpawnDelay -= 100;
            }
            else
            {
                Logger->Log(JAMCT_Logger::INFO,"SpawnEngine","Spawn Delay Maxed out! Will not go lower than: " + std::to_string(SpawnDelay));
            }
            Logger->Log(JAMCT_Logger::INFO,"SpawnEngine","Reached Level " + std::to_string(Level) + " Spawn Delay = " + std::to_string(SpawnDelay));
        }
        //Delay
        std::chrono::milliseconds dura(SpawnDelay);
        std::this_thread::sleep_for( dura );
        int SpawnSide = 0;
        for (int i=0; i<(Level); i++)
        {
            SpawnSide = theWorld->RandomNumber(4,1);
            EnemyShip *pinkguy = new EnemyShip(Logger,GetSpawnLoc(true,SpawnSide),GetSpawnLoc(false,SpawnSide),10,theWorld,thePlayer);
            theWorld->AddEntity(pinkguy);
        }
        if (Level > 1)
        {
            for (int i=0; i<(round(Level/3)); i++)
            {
                SpawnSide = theWorld->RandomNumber(4,1);
                EnemyFighter *fighter = new EnemyFighter(Logger,GetSpawnLoc(true,SpawnSide),GetSpawnLoc(false,SpawnSide),10,theWorld,thePlayer);
                theWorld->AddEntity(fighter);
            }
        }
    }
}

void SpawnEngine::SetLevel(int newlevel)
{
    SpawnEngine::Level = newlevel;
}

