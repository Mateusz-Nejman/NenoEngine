#include "Primitives.h"


namespace neno
{
	void Primitives::DrawRectangle(int x, int y, int width, int height, Color color)
	{
        glColor3f(color.r,color.g,color.b);

        // pocz�tek definicji wielok�ta
        glBegin(GL_QUADS);

        // kolejne wierzcho�ki wielok�ta
        glVertex3f(x, y, 0.0);
        glVertex3f(x, y+height, 0.0);
        glVertex3f(x+width,y+height, 0.0);
        glVertex3f(x+width, y, 0.0);

        // koniec definicji prymitywu
        glEnd();
        glFlush();
	}
}