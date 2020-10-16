#include "pch.h"
#include "Rectangle.h"

namespace Neno
{
	namespace Core
	{
		Rectangle::~Rectangle()
		{
			delete position;
			delete size;
			position = nullptr;
			size = nullptr;
		}

		Rectangle::Rectangle(int x, int y, int width, int height)
		{
			this->position = new Point(x, y);
			this->size = new Point(width, height);
		}

		bool Rectangle::Contains(Point point)
		{
			bool containsX = point.x > position->x && point.x < position->x + size->x;
			bool containsY = point.y > position->y && point.y < position->y + size->y;

			return containsX && containsY;
		}
	}
}