#ifndef WORLD_HPP_INCLUDED
#define WORLD_HPP_INCLUDED
#include "JAMCT_Logger.hpp"
#include "Entity.hpp"
#include <GLFW/glfw3.h>
#include <vector>
#include <map>
class World {

private:
    std::vector<Entity*> WorldItems;
    std::vector<Entity*> CleanWorldItems;
    std::vector<Entity*>::iterator CleanWorldItemsIterator;
    JAMCT_Logger *Logger;
    GLFWwindow* Window;
    int HEIGHT;
    int WIDTH;
    const int BROAD_DETECTION_RANGE = 100;
    std::map<Entity*, std::vector<Entity*>*> EntityColls; //A Map Containing a pointer to a Vectory of Object. Weird :)
    std::map<Entity*, std::vector<Entity*>*>::iterator EntityCollsIterator;

public:
    void AddEntity(Entity *newEntity);
    void Render();
     World(JAMCT_Logger *in_logger,GLFWwindow* in_window,int screen_hight,int screen_width);
    ~World();
    bool EqualsBoundCheck(int loc, int target, int bound);
    void RunCollisionDetection();

};


#endif // WORLD_HPP_INCLUDED
