#include "DrawUtil.hpp"
#include "About.hpp"
#include <GLFW/glfw3.h>
#include <math.h>

void DrawDebug(int XLoc, int YLoc) {
    DrawUtil_DrawCircle(XLoc,YLoc,2,160,1,1,1);
}

void DrawUtil_DrawCircle(float cx, float cy, float rad, int num_segments, float r, float g, float b ) {
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

void DrawUtil_DrawTraingle(int XLocation, int YLocation, int Height, int Width, float r, float g, float b,int Direction)
{
    glBegin(GL_TRIANGLES);
    glColor3f(r,g,b);
    switch(Direction)
    {
    case 0:
        glVertex2f(XLocation,YLocation+(Height /2));
        glVertex2f(XLocation+(Width /2),YLocation-(Height / 2));
        glVertex2f(XLocation-(Width/2),YLocation-(Height/2));
        break;
    case 45:
        glVertex2f(XLocation+(Width/2),YLocation+(Height/2));
        glVertex2f(XLocation+(Width/2),YLocation-(Height/2));
        glVertex2f(XLocation-(Width/2),YLocation+(Height/2));
        break;
    case 90:
        glVertex2f(XLocation-(Width/2),YLocation+(Height/2));
        glVertex2f(XLocation+(Width/2),YLocation);
        glVertex2f(XLocation-(Width/2),YLocation-(Height/2));
        break;
    case 135:
        glVertex2f(XLocation+(Width/2),YLocation-(Height/2));
        glVertex2f(XLocation-(Width/2),YLocation-(Height/2));
        glVertex2f(XLocation+(Width/2),YLocation+(Height/2));
        break;
    case 180:
        glVertex2f(XLocation,YLocation-(Height /2));
        glVertex2f(XLocation-(Width /2),YLocation+(Height / 2));
        glVertex2f(XLocation+(Width/2),YLocation+(Height/2));
        break;
    case 225:
        glVertex2f(XLocation-(Width/2),YLocation-(Height/2));
        glVertex2f(XLocation-(Width/2),YLocation+(Height/2));
        glVertex2f(XLocation+(Width/2),YLocation-(Height/2));
        break;
    case 270:
        glVertex2f(XLocation+(Width/2),YLocation-(Height/2));
        glVertex2f(XLocation-(Width/2),YLocation);
        glVertex2f(XLocation+(Width/2),YLocation+(Height/2));
        break;
    case 315:
        glVertex2f(XLocation-(Width/2),YLocation+(Height/2));
        glVertex2f(XLocation+(Width/2),YLocation+(Height/2));
        glVertex2f(XLocation-(Width/2),YLocation-(Height/2));
        break;
    }
    glEnd();
    if (_DRAW_DEBUG_) {DrawDebug(XLocation,YLocation);}
}


void DrawUtil_DrawSquare(int XLocation, int YLocation, int Height, int Width, float r, float g, float b) {
    glBegin(GL_QUADS);
    glColor3f(r,g,b);
    glVertex2f( (XLocation - (Width/2) )  , YLocation - (Height/2));
    glVertex2f(XLocation - (Width/2), YLocation + (Height/2) );
    glVertex2f(XLocation + (Width/2), YLocation + (Height/2));
    glVertex2f(XLocation + (Width/2), YLocation - (Height/2) );
    glEnd();
    if (_DRAW_DEBUG_) {DrawDebug(XLocation,YLocation);}
}
