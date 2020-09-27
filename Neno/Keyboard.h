#pragma once
#include <GL/glut.h>

#define NENO_KEY_F1 257
#define NENO_KEY_F2 258
#define NENO_KEY_F3 259
#define NENO_KEY_F4 260
#define NENO_KEY_F5 261
#define NENO_KEY_F6 262
#define NENO_KEY_F7 263
#define NENO_KEY_F8 264
#define NENO_KEY_F9 265
#define NENO_KEY_F10 266
#define NENO_KEY_F11 267
#define NENO_KEY_F12 268

#define NENO_KEY_LEFT 356
#define NENO_KEY_UP 357
#define NENO_KEY_RIGHT 358
#define NENO_KEY_DOWN 359

#define NENO_KEY_PAGEUP 360
#define NENO_KEY_PAGEDOWN 361
#define NENO_KEY_HOME 362
#define NENO_KEY_END 363
#define NENO_KEY_INSERT 364

#define NENO_KEY_LSHIFT 368
#define NENO_KEY_RSHIFT 369

#define NENO_KEY_LCTRL 370
#define NENO_KEY_RCTRL 371
#define NENO_KEY_RALT 372




using namespace std;
namespace neno
{
	class Keyboard
	{
	private:
		
	public:
		static int key_pressed[512];
		static int old_key_pressed[512];
		static void Initialize();
		static void ProcessChar(int key, int value);
		static bool IsDown(int key);
		static bool IsUp(int key);
		static bool IsPressed(int key);
		static bool IsReleased(int key);
		static bool IsShift();
		static bool IsCtrl();
		static bool IsAlt();
		static void AfterUpdate();
	};
}

