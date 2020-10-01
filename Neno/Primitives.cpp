#include "Primitives.h"

namespace neno
{
	void Primitives::DrawRectangle(int x, int y, int width, int height, Color color)
	{
        glColor4d(color.r,color.g,color.b, color.a);
        glBegin(GL_QUADS);
        glVertex2d(x, y);
        glVertex2d(x, y+height);
        glVertex2d(x+width,y+height);
        glVertex2d(x+width, y);
        glEnd();
        glFlush();
	}

    void Primitives::DrawRectangleOutline(int x, int y, int width, int height, int lineWidth, Color color)
    {
        glColor4d(color.r, color.g, color.b, color.a);
        glLineWidth(lineWidth);
        glBegin(GL_LINES);
        glVertex2d(x, y);
        glVertex2d(x+width, y);
        glVertex2d(x + width, y);
        glVertex2d(x + width, y + height);
        glVertex2d(x + width, y + height);
        glVertex2d(x, y + height);
        glVertex2d(x, y + height);
        glVertex2d(x, y);
        glEnd();
        glFlush();
    }

    void Primitives::DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, Color color)
    {
        glColor4d(color.r, color.g, color.b, color.a);
        glBegin(GL_TRIANGLES);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
        glVertex2d(x3, y3);
        glEnd();
        glFlush();
    }

    void Primitives::DrawLine(int x1, int y1, int x2, int y2, int lineWidth, Color color)
    {
        glColor4d(color.r, color.g, color.b, color.a);
        glLineWidth(lineWidth);
        glBegin(GL_LINES);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
        glEnd();
        glFlush();
    }

    void Primitives::DrawPolygon(std::vector<int> points, Color color)
    {
        glColor4d(color.r, color.g, color.b, color.a);
        glBegin(GL_POLYGON);
        for (int a = 0; a < points.size(); a += 2)
        {
            glVertex2d(points[a], points[a + 1]);
        }
        glEnd();
        glFlush();
    }
}