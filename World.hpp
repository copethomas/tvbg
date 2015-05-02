#ifndef WORLD_HPP_INCLUDED
#define WORLD_HPP_INCLUDED
#include "JAMCT_Logger.hpp"
#include "Entity.hpp"
#include "Score.hpp"
#include <GLFW/glfw3.h>
#include <vector>
#include <map>
class World {

public:
    void AddEntity(Entity *newEntity);
    void Render();
     World(JAMCT_Logger *in_logger,GLFWwindow* in_window,int screen_hight,int screen_width);
    ~World();
    bool EqualsBoundCheck(int loc, int target, int bound);
    void RunCollisionDetection();
    void AddPoints(int points);
    enum GameStateType {START,RUNNING,GAMEOVER};
    void SetGameState (GameStateType type);
    int GetGameState();
    int RandomNumber(int hight, int low);
    int GetScore();
    int GetScreenHeight();
    int GetScreenWidth();
    void Respawn();
    int GetEntitys();
    int GetFPS();
    void ProcessFPS();

private:
    GameStateType GameState = START;
    std::vector<Entity*> WorldItems;
    JAMCT_Logger *Logger;
    GLFWwindow* Window;
    int HEIGHT;
    int WIDTH;
    const int BROAD_DETECTION_RANGE = 100;
    std::map<Entity*, std::vector<Entity*>*> EntityColls; //A Map Containing a pointer to a Vectory of Object. Weird :)
    std::map<Entity*, std::vector<Entity*>*>::iterator EntityCollsIterator;
    Score *Scoreboard;
    int CurrentFPS;

};


#endif // WORLD_HPP_INCLUDED
