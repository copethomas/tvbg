#ifndef WORLD_HPP_INCLUDED
#define WORLD_HPP_INCLUDED
#include "JAMCT_Logger.hpp"
#include "Entity.hpp"
#include <GLFW/glfw3.h>
#include <vector>
class World {

private:
    std::vector<Entity*> WorldItems;
    JAMCT_Logger *Logger;
    GLFWwindow* Window;

public:
    void AddEntity(Entity *newEntity);
    void Render();
     World(JAMCT_Logger *in_logger,GLFWwindow* in_window);
    ~World();

};


#endif // WORLD_HPP_INCLUDED
