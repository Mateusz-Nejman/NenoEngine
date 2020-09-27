#include "Keyboard.h"

namespace neno
{
	int Keyboard::key_pressed[256];
	void Keyboard::Initialize()
	{
		for (int a = 0; a < 256; a++)
			key_pressed[a] = 0;
	}

	void Keyboard::ProcessChar(char _char, int value)
	{
		int charId = (int)_char;
		key_pressed[charId] = value;
	}

	bool Keyboard::IsPressed(char _char)
	{
		int charId = (int)_char;
		return key_pressed[charId] == 1;
	}
}