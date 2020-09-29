#include "Primitives.h"
#include <iostream>

namespace neno
{
	void Primitives::DrawRectangle(int x, int y, int width, int height, Color color)
	{
        glColor4d(color.r,color.g,color.b, color.a);
        glBegin(GL_QUADS);
        glVertex2i(x, y);
        glVertex2i(x, y+height);
        glVertex2i(x+width,y+height);
        glVertex2i(x+width, y);
        glEnd();
        glColor4d(Color::White.r, Color::White.g, Color::White.b, Color::White.a);
        glFlush();
	}

    void Primitives::DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, Color color)
    {
        glColor4d(color.r, color.g, color.b, color.a);
        glBegin(GL_TRIANGLES);
        glVertex2i(x1, y1);
        glVertex2i(x2, y2);
        glVertex2i(x3, y3);
        glEnd();
        glColor4d(Color::White.r, Color::White.g, Color::White.b, Color::White.a);
        glFlush();
    }

    void Primitives::DrawLine(int x1, int y1, int x2, int y2, int lineWidth, Color color)
    {
        glColor4d(color.r, color.g, color.b, color.a);
        glLineWidth(lineWidth);
        glBegin(GL_LINES);
        glVertex2i(x1, y1);
        glVertex2i(x2, y2);
        glEnd();
        glColor4d(Color::White.r, Color::White.g, Color::White.b, Color::White.a);
        glLineWidth(1);
        glFlush();
    }

    void Primitives::DrawPolygon(std::vector<int> points, Color color)
    {
        glColor4d(color.r, color.g, color.b, color.a);
        glBegin(GL_POLYGON);
        for (int a = 0; a < points.size(); a+=2)
        {
            glVertex2i(points[a], points[a+1]);
        }
        glEnd();
        glColor4d(Color::White.r, Color::White.g, Color::White.b, Color::White.a);
        glFlush();
    }
}