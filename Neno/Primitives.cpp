#include "Primitives.h"

namespace neno
{
	void Primitives::DrawRectangle(int x, int y, int width, int height, Color color)
	{
        glColor3f(color.r,color.g,color.b);
        glBegin(GL_QUADS);
        glVertex3f(x, y, 0.0);
        glVertex3f(x, y+height, 0.0);
        glVertex3f(x+width,y+height, 0.0);
        glVertex3f(x+width, y, 0.0);
        glEnd();
        glFlush();
	}

    void Primitives::DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, Color color)
    {
        glColor3f(color.r, color.g, color.b);
        glBegin(GL_TRIANGLES);
        glVertex3f(x1, y1, 0.0);
        glVertex3f(x2, y2, 0.0);
        glVertex3f(x3, y3, 0.0);
        glEnd();
        glFlush();
    }
}