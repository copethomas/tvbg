#include "World.hpp"
#include "MovableEntity.hpp"
#include <assert.h>
#include <vector>
#include <map>

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

void World::RunCollisionDetection()
{
    //Broad Detection First. "What Entitys 'Could' Collide?"
    bool colDetected = false;
    for (Entity* collisionEntity : World::WorldItems) {
        colDetected = false; //Assuming no Detections will be made.
        std::vector<Entity*>* colideEntities = new std::vector<Entity*>; //Here I'm creating a pointer to a new vector of entites in memory.
        for (Entity* checkEntity : World::WorldItems) {
            //If the Entity Has the Possibility of Coliding on the X or Y then add them to the check list.
            if ((EqualsBoundCheck(collisionEntity->GetXLocation(),checkEntity->GetXLocation(),BROAD_DETECTION_RANGE))|(EqualsBoundCheck(collisionEntity->GetYLocation(),checkEntity->GetYLocation(),BROAD_DETECTION_RANGE))) {
                colDetected = true;
                //Right We have Found Someone. Add them to the list
                Logger->Log(JAMCT_Logger::INFO,"CollisionDetection","Possibilite Detected");
                colideEntities->push_back(checkEntity);
            }
        }
        if (colDetected == false) {
            //If we go through all that and dont find anything then delete the unused mem.
            delete colideEntities;
        }else{
            //We did find some detections so add the entity and the vector of detections to the map to be checked in the next stage.
            EntityColls.emplace(collisionEntity,colideEntities);
        }
    }

    //Next up if processing the Possible Mataches for a Collision.
    bool colConfirmed = false;
    for (EntityCollsIterator = EntityColls.begin(); EntityCollsIterator != EntityColls.end(); EntityCollsIterator++)
    {
        Entity* entityInQuestion = EntityCollsIterator->first;
        std::vector<Entity*>* entityToCheck = EntityCollsIterator->second;
        //Loop through Entitys To Check at match aginst the entity inquestion.
        for (Entity* checkme : *entityToCheck) { //Using the '*' here to dereference the vector.
            //Perform Collision Detections between two enties.
            colConfirmed = false;
            if ((EqualsBoundCheck(entityInQuestion->GetXLocation(),checkme->GetXLocation(),(entityInQuestion->GetWidth()+checkme->GetWidth())))|(EqualsBoundCheck(entityInQuestion->GetYLocation(),checkme->GetYLocation(),(entityInQuestion->GetHeight()+checkme->GetHeight())))) {
                    //WE HAVE A COLLISION!
                    entityInQuestion->Colision(checkme);
            }
        }
        delete entityToCheck; //Delete the Vector We dont need it.
    }
    //DONT FORGET TO DELETE WHEN DONE!!!
    EntityColls.clear();
}


