#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include "JAMCT_Logger.h"
#include "Entity.hpp"
#include "World.hpp"

void Fatal_Error(std::string message,JAMCT_Logger *logger) {
    logger->Log(JAMCT_Logger::CRIT,"Main","--->Fatal Application Error<---");
    logger->Log(JAMCT_Logger::CRIT,"Main","Reason: " + message);
    logger->Shutdown();
    delete logger;
    exit(EXIT_FAILURE);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main() {
    std::cout << "TVBG Version 0.0.2.8\n";
    std::cout << "Created by Thomas Cope\n\n";
    std::cout << "Starting Application...\n\n";
    JAMCT_Logger *logger  = new JAMCT_Logger(0);
    logger->Log(JAMCT_Logger::INFO,"Main","Starting GLFW...");
    if (!glfwInit()) {
        Fatal_Error("Unable to start GLFW",logger);
    }
    GLFWwindow* window;
    logger->Log(JAMCT_Logger::INFO,"Main","Creating Window...");
    int widthMM, heightMM;
    const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    heightMM = mode->height;
    widthMM = mode->width;
    logger->Log(JAMCT_Logger::INFO,"Main","Window Size = " + std::to_string(widthMM) + " X " + std::to_string(heightMM));
    window = glfwCreateWindow(widthMM,heightMM,"TVBG V0.0.2.8",glfwGetPrimaryMonitor(),NULL);
    if (!window) {
        glfwTerminate();
        Fatal_Error("Could not create Window",logger);
    }
    Entity *ship = new Entity(logger);
    World *world = new World(logger,window);
    world->AddEntity(ship);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window)) {
        world->Render();
    }
    delete world;
    logger->Log(JAMCT_Logger::INFO,"Main","Window Closes. Application going down...");
    glfwDestroyWindow(window);
    glfwTerminate();
    logger->Shutdown();
    delete logger;
    return 0;
}
