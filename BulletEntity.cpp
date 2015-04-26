#include "BulletEntity.hpp"
#include <GLFW/glfw3.h>
#include <math.h>

void DrawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f,0.0f,0.0f); //Blue Player
	for(int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component
		glVertex2f(x + cx, y + cy);//output vertex
	}
	glEnd();
}


bool BulletEntity::Draw()
{
 DrawCircle(XLocation,YLocation,4,160);
 return true;
}

bool BulletEntity::DefaultMove()
{
    MoveUp();
}

BulletEntity::BulletEntity(JAMCT_Logger* in_logger, int startx, int starty, int heading_direction): MovableEntity(in_logger,startx,starty)
{
    BulletEntity::Direction = heading_direction;
    BulletEntity::Speed = 20;
}
