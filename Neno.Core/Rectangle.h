#ifndef NENO_RECTANGLE_H
#define NENO_RECTANGLE_H
#include "Point.h"

namespace Neno
{
	namespace Core
	{
		class Rectangle
		{
		public:
			~Rectangle();
			Rectangle(int x, int y, int width, int height);
			Point* position;
			Point* size;
			bool Contains(Point point);
		};
	}
}
#endif