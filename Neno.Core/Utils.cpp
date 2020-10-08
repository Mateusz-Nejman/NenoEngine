#include "pch.h"
#include "Utils.h"

namespace Neno
{
	namespace Core
	{
		char Utils::utilsBuffer[255] = "";
		char* Utils::FilePath(const char* fileName)
		{
			return _fullpath(utilsBuffer, fileName, sizeof(utilsBuffer));
		}
	}
}