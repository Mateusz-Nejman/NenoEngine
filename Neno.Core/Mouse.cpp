#include "pch.h"
#include "Mouse.h"

namespace Neno
{
	namespace Core
	{
		int Mouse::mouse_data[5];
		int Mouse::old_mouse_data[5];

		void Mouse::Initialize()
		{
			mouse_data[0] = 1;
			mouse_data[1] = 1;
			mouse_data[2] = 1;
			mouse_data[3] = 0;
			mouse_data[4] = 0;

			old_mouse_data[0] = 1;
			old_mouse_data[1] = 1;
			old_mouse_data[2] = 1;
			old_mouse_data[3] = 0;
			old_mouse_data[4] = 0;
		}

		void Mouse::AfterUpdate()
		{
			for (int a = 0; a < 5; a++)
			{
				old_mouse_data[a] = mouse_data[a];
			}
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

		bool Mouse::LeftDown()
		{
			return mouse_data[0] == GLFW_PRESS;
		}

		bool Mouse::MiddleDown()
		{
			return mouse_data[1] == GLFW_PRESS;
		}

		bool Mouse::RightDown()
		{
			return mouse_data[2] == GLFW_PRESS;
		}

		bool Mouse::LeftUp()
		{
			return mouse_data[0] == 0;
		}

		bool Mouse::MiddleUp()
		{
			return mouse_data[1] == 0;
		}

		bool Mouse::RightUp()
		{
			return mouse_data[2] == 0;
		}

		bool Mouse::LeftPressed()
		{
			return mouse_data[0] == 1 && old_mouse_data[0] == 0;
		}

		bool Mouse::MiddlePressed()
		{
			return mouse_data[1] == 1 && old_mouse_data[1] == 0;
		}

		bool Mouse::RightPressed()
		{
			return mouse_data[2] == 1 && old_mouse_data[2] == 0;
		}

		bool Mouse::LeftReleased()
		{
			return mouse_data[0] == 0 && old_mouse_data[0] == 1;
		}

		bool Mouse::MiddleReleased()
		{
			return mouse_data[1] == 0 && old_mouse_data[1] == 1;
		}

		bool Mouse::RightReleased()
		{
			return mouse_data[2] == 0 && old_mouse_data[2] == 1;
		}
	}
}