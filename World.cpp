#include "World.hpp"


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
    for (Entity* renderEntity : World::WorldItems) {
      if (!renderEntity->Draw()) {
          Logger->Log(JAMCT_Logger::INFO,"World","Rendering Error Detected!");
        }
    }
    glfwSwapBuffers(World::Window);
    glfwPollEvents();
}

void World::AddEntity(Entity *newEntity) {
    Logger->Log(JAMCT_Logger::INFO,"World","Adding new Entity..");
    World::WorldItems.push_back(newEntity);
}
