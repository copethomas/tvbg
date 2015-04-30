#include "World.hpp"
#include "MovableEntity.hpp"
#include <algorithm>
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
    if (WorldItems.size() == 0) {
        Logger->Log(JAMCT_Logger::EMER,"World","No Extities to Render!");
        assert(WorldItems.size() != 0);
    }

    auto WorldItemsIterator = WorldItems.begin();
    while(WorldItemsIterator != WorldItems.end()) {
    int index = std::distance(WorldItems.begin(), WorldItemsIterator);
    Entity* renderEntity = WorldItems.at(index);
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
        //Process Dead Entities.
        if (renderEntity->GetDead()) {
            WorldItemsIterator = WorldItems.erase(WorldItemsIterator);
        }else {
            ++WorldItemsIterator;
        }
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

// TODO (tom#1#28/04/15): Need to opertimise this check
bool PosibbleCollision(Entity *target , Entity *check, int bound) {

    int x = target->GetXLocation();
    int y = target->GetYLocation();

    int x_upper = x + bound;
    int x_lower = x - bound;

    int y_upper = y + bound;
    int y_lower = y - bound;

    if (!((check->GetXLocation() < x_upper)&&(check->GetXLocation() > x_lower)))   {
        return false;
    }

    if (!((check->GetYLocation() < y_upper)&&(check->GetYLocation() > y_lower)))   {
        return false;
    };
    return true;
}

bool CheckCollision(Entity *target , Entity *check) {
    if (target->GetXLocation() < check->GetXLocation() + check->GetWidth() && target->GetXLocation() + target->GetWidth() > check->GetXLocation() && target->GetYLocation() < check->GetYLocation() + check->GetHeight() && target->GetHeight() + target->GetYLocation() > check->GetYLocation()) {
        return true;
    }else{
        return false;
    }
}

void World::RunCollisionDetection()
{

  //  if (WorldItems.size() == 3) {
//      Logger->Log(JAMCT_Logger::INFO,"CollisionDetection","NOW!!!");
   // }

    //Broad Detection First. "What Entitys 'Could' Collide?"
    bool colDetected = false;
     for (Entity* collisionEntity : World::WorldItems) {
        colDetected = false; //Assuming no Detections will be made.
        std::vector<Entity*>* colideEntities = new std::vector<Entity*>; //Here I'm creating a pointer to a new vector of entites in memory.
        for (Entity* checkEntity : World::WorldItems) {
            if (!(checkEntity==collisionEntity)) { //An Entity Can't collide with it's seld :D
            //If the Entity Has the Possibility of Coliding on the X or Y then add them to the check list.
            if (PosibbleCollision(collisionEntity,checkEntity,BROAD_DETECTION_RANGE)) {
                colDetected = true;
                //Right We have Found Someone. Add them to the list
                colideEntities->push_back(checkEntity);
            }
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
    //if (EntityColls.size() > 0) {
    //    Logger->Log(JAMCT_Logger::INFO,"CollisionDetection","Detected " + std::to_string(EntityColls.size()) + " possible Collisions." );
   // }
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
            if (CheckCollision(entityInQuestion,checkme)) {
                    //WE HAVE A COLLISION!
                    //Logger->Log(JAMCT_Logger::INFO,"CollisionDetection","Detected");
                    entityInQuestion->Colision(checkme);
            }
        }
        delete entityToCheck; //Delete the Vector We dont need it.
    }
    //DONT FORGET TO DELETE WHEN DONE!!!
    EntityColls.clear();
}


