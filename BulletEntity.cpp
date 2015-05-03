#include "BulletEntity.hpp"
#include <GLFW/glfw3.h>
#include <math.h>

void BulletEntity::DrawCircle(float cx, float cy, float rad, int num_segments, float r, float g, float b )
{
	glBegin(GL_LINE_LOOP);
	glColor3f(r,g,b); //Blue Player
	for(int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
		float x = rad * cosf(theta);//calculate the x component
		float y = rad * sinf(theta);//calculate the y component
		glVertex2f(x + cx, y + cy);//output vertex
	}
	glEnd();
}


bool BulletEntity::Draw()
{
 DrawCircle(XLocation,YLocation,Width,160,1.0f,0.0f,0.0f);
 return true;
}

bool BulletEntity::DefaultMove()
{
    MoveUp();
}

void BulletEntity::Colision(Entity* colided_with)
{
    std::string colided_with_name = std::string(typeid(*colided_with).name());
    if (  colided_with_name.compare("9EnemyShip") == 0  ) {
       BulletEntity::SetDead(true);
    }
}


BulletEntity::BulletEntity(JAMCT_Logger* in_logger, int startx, int starty, int heading_direction): MovableEntity(in_logger,startx,starty)
{
    BulletEntity::Direction = heading_direction;
    BulletEntity::Speed = 20;
    Width = 4;
    Height = 6;
    Health = 1;
    Damage = 1;
}
