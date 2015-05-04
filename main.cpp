#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include "JAMCT_Logger.hpp"
#include "World.hpp"
#include "PlayerShip.hpp"
#include "Text.hpp"
#include "TextStats.hpp"
#include "SpawnEngine.hpp"
#include "Message.hpp"
#include "About.hpp"

void Fatal_Error(std::string message,JAMCT_Logger *logger) {
    logger->Log(JAMCT_Logger::CRIT,"Main","--->Fatal Application Error<---");
    logger->Log(JAMCT_Logger::CRIT,"Main","Reason: " + message);
    logger->Shutdown();
    delete logger;
    exit(EXIT_FAILURE);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

}

int main() {
    std::cout << "TVBG Version " << _APP_VERSION_ << "\n";
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
    std::string AppName = "TVBG Version " + _APP_VERSION_;
    //window = glfwCreateWindow(widthMM,heightMM,AppName.c_str(),glfwGetPrimaryMonitor(),NULL);
    window = glfwCreateWindow(widthMM,heightMM,"TVBG V0.0.2.8",NULL,NULL);
    if (!window) {
        glfwTerminate();
        Fatal_Error("Could not create Window",logger);
    }
    World *world = new World(logger,window,heightMM,widthMM);
    PlayerShip *thePlayer = new PlayerShip(logger,(widthMM/2),(heightMM/2),10,world);
    world->AddEntity(thePlayer);
    SpawnEngine *spawner = new SpawnEngine(logger,world,thePlayer);
    spawner->SetPause(true);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    glViewport(0, 0, widthMM, heightMM);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, widthMM, 0.0f, heightMM, 0.0f, 1.0f);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
    //***Title Text***
    Text *title = new Text(logger,(widthMM/3),(10),50,"Push <enter> to Start");
    Text *youDied = new Text(logger,(widthMM/3),(10),50,"Push <enter> to Respawn");
    TextStats *stats = new TextStats(logger,widthMM - 90,heightMM - 20,15,world);
    youDied->SetHidden(true);
    world->AddEntity(title);
    world->AddEntity(youDied);
    world->AddEntity(stats);
    while (!glfwWindowShouldClose(window)) {
        //**********StartGame************
        if (world->GetGameState() == World::START) {
            if (glfwGetKey(window,GLFW_KEY_ENTER)){
                title->SetHidden(true);
                world->SetGameState(World::RUNNING);
                spawner->SetPause(false);
            }
        }
        //**********End START GAME*******


        //*********MAIN GAME*************
        if (world->GetGameState() == World::RUNNING) {
            //Process Key Input.
            thePlayer->WKey((glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS));
            thePlayer->AKey((glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS));
            thePlayer->SKey((glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS));
            thePlayer->DKey((glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS));
            thePlayer->DebugKey((glfwGetKey(window, GLFW_KEY_APOSTROPHE) == GLFW_PRESS));
            if ((glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)) {
                thePlayer->Shoot();
            }
        }
        //************END MAIN GAME***********

        //************START GAMEOVER***********
        if (world->GetGameState() == World::GAMEOVER) {
                youDied->SetHidden(false);
                spawner->SetPause(true);
                if (glfwGetKey(window,GLFW_KEY_ENTER)){
                    world->SetGameState(World::RUNNING);
                    youDied->SetHidden(true);
                    world->Respawn();
                    spawner->SetPause(false);
                    spawner->SetLevel(1);
                }
        }
        thePlayer->KeyCoolDown();
        world->Render();
        world->RunCollisionDetection();
        world->ProcessFPS();
    }
    title->SetHidden(true);
    youDied->SetHidden(true);
    logger->Log(JAMCT_Logger::INFO,"Main","*Shutdown Requested*");
    Message *shutdownmsg = new Message(logger,(widthMM/3),(10),50,"Shutting Down. Please wait...",1500);
    world->AddEntity(shutdownmsg);
    world->Render();
    spawner->Shutdown();
    logger->Log(JAMCT_Logger::INFO,"Main","Window Closes. Application going down...");
    glfwDestroyWindow(window);
    glfwTerminate();
    delete spawner;
    delete world; //World Shutdown is part of the deconstructor.
    logger->Flush();
    logger->Shutdown();
    delete logger;
    return 0;
}
