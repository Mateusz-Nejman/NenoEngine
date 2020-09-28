#ifndef MOUSE_H
#define MOUSE_H

#include <GL/glut.h>

namespace neno
{
	class Mouse
	{
	public:
		static int mouse_data[5];
		static void Initialize();
		static void ProcessClick(int button, int state, int x, int y);
		static int GetX();
		static int GetY();
		static bool LeftPressed();
		static bool RightPressed();
		static bool MiddlePressed();
	};
}

#endif