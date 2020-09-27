#include "Utils.h"

namespace neno
{
	char Utils::utilsBuffer[255] = "";
	char* Utils::FilePath(const char* fileName)
	{
		return _fullpath(utilsBuffer, fileName, sizeof(utilsBuffer));
	}
}