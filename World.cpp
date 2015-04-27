#include "World.hpp"
#include "MovableEntity.hpp"
#include <assert.h>

World::World(JAMCT_Logger *in_logger,GLFWwindow* in_window,int screen_hight,int screen_width): Logger(in_logger), Window(in_window) {
    Logger->Log(JAMCT_Logger::INFO,"World","Loading World...");
    World::WIDTH = screen_width;
    World::HEIGHT = screen_hight;

}

World::~World() {
    Logger->Log(JAMCT_Logger::INFO,"World","World Shutting Down...");
    int i = 0;
    for (Entity* renderEntity : World::WorldItems) {
        delete renderEntity;
        i++;
    }
    Logger->Log(JAMCT_Logger::INFO,"World","Cleared " + std::to_string(i) + " Entitys");
}

void World::Render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    int counter = 0;
    if (WorldItems.size() == 0) {
        Logger->Log(JAMCT_Logger::EMER,"World","No Extities to Render!");
        assert(WorldItems.size() != 0);
    }
    for (Entity* renderEntity : World::WorldItems) {
      if (!renderEntity->Draw()) {
          Logger->Log(JAMCT_Logger::INFO,"World","Rendering Error Detected!");
        }
        if ((renderEntity->GetXLocation() < 0) | (renderEntity->GetYLocation() < 0) | (renderEntity->GetYLocation() > HEIGHT) | (renderEntity->GetXLocation() > WIDTH) ) {
           // Logger->Log(JAMCT_Logger::AERT,"World","Dead Entity Loc: X=" + std::to_string(renderEntity->GetXLocation()) + " Y=" + std::to_string(renderEntity->GetYLocation()) + " WIDTH=" + std::to_string(WIDTH) + " HEIGHT=" + std::to_string(HEIGHT));
            renderEntity->SetDead(true);
        }
        MovableEntity *test;
        test = (MovableEntity*) renderEntity;
        test->DefaultMove();
        //Last Kill them if needed.
        if (renderEntity->GetDead()) {
            WorldItems.erase(WorldItems.begin() + counter);
            delete renderEntity;
        }
        counter++;
    }
    glFlush();
    glFinish();
    glfwSwapInterval(1);
    glfwSwapBuffers(World::Window);
    glfwPollEvents();
}

void World::AddEntity(Entity *newEntity) {
   // Logger->Log(JAMCT_Logger::INFO,"World","Adding new Entity..");
    World::WorldItems.push_back(newEntity);
}

bool World::EqualsBoundCheck(int loc, int target,int bound)
{
    if ((loc > (target - bound)) & (loc < (target + bound))) {
        return true;
    }else{
        return false;
    }
}

