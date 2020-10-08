#include "pch.h"
#include "Mouse.h"

namespace Neno
{
	namespace Core
	{
		int Mouse::mouse_data[5];
		void Mouse::Initialize()
		{
			mouse_data[0] = 1;
			mouse_data[1] = 1;
			mouse_data[2] = 1;
			mouse_data[3] = 0;
			mouse_data[4] = 0;
		}

		void Mouse::ProcessClick(int button, int state, int x, int y)
		{
			if (button >= 0)
				mouse_data[button] = state;
			mouse_data[3] = x;
			mouse_data[4] = y;
		}

		int Mouse::GetX()
		{
			return mouse_data[3];
		}

		int Mouse::GetY()
		{
			return mouse_data[4];
		}

		bool Mouse::LeftPressed()
		{
			return mouse_data[0] == GLFW_PRESS;
		}

		bool Mouse::MiddlePressed()
		{
			return mouse_data[1] == GLFW_PRESS;
		}

		bool Mouse::RightPressed()
		{
			return mouse_data[2] == GLFW_PRESS;
		}
	}
}