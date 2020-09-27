#pragma once
#include <iostream>

using namespace std;
namespace neno
{
	class Keyboard
	{
	private:
		
	public:
		static int key_pressed[256];
		static void Initialize();
		static void ProcessChar(char _char, int value);
		static bool IsPressed(char _char);
	};
}

