#pragma once
#include <stdlib.h>

namespace neno
{
	class Utils
	{
	public:
		static char utilsBuffer[255];
		static char* FilePath(const char* fileName);
	};
}

