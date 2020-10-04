#include "Keyboard.h"

namespace neno
{
	int Keyboard::key_pressed[512];
	int Keyboard::old_key_pressed[512];

	void Keyboard::Initialize()
	{
		for (int a = 0; a < 512; a++)
		{
			key_pressed[a] = 0;
			old_key_pressed[a] = 0;
		}
	}

	void Keyboard::AfterUpdate()
	{
		for (int a = 0; a < 512; a++)
		{
			old_key_pressed[a] = key_pressed[a];
		}
	}

	void Keyboard::ProcessChar(int key, int value)
	{
		key_pressed[key] = value;
	}

	bool Keyboard::IsDown(int key)
	{
		return key_pressed[key] == 1;
	}

	bool Keyboard::IsUp(int key)
	{
		return key_pressed[key] == 0;
	}

	bool Keyboard::IsPressed(int key)
	{
		return key_pressed[key] == 1 && old_key_pressed[key] == 0;
	}

	bool Keyboard::IsReleased(int key)
	{
		return key_pressed[key] == 0 && old_key_pressed[key] == 1;
	}
}