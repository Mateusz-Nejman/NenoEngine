#pragma once
#ifndef NENO_PRIMITIVES_H
#define NENO_PRIMITIVES_H

#include <GL/glew.h>
#include <vector>
#include "Color.h"

namespace Neno
{
	namespace Core
	{
		class Primitives
		{
		public:
			static void DrawRectangle(int x, int y, int width, int height, Color color);
			static void DrawRectangleOutline(int x, int y, int width, int height, int lineWidth, Color color);
			static void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, Color color);
			static void DrawLine(int x1, int y1, int x2, int y2, int lineWidth, Color color);
			static void DrawPolygon(std::vector<int> points, Color color);
		};
	}
}

#endif