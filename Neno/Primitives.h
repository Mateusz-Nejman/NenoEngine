#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <GL/glut.h>
#include "Color.h"

namespace neno
{
	class Primitives
	{
	public:
		static void DrawRectangle(int x, int y, int width, int height, Color color);
		static void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, Color color);
	};

}

#endif