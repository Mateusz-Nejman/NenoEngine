#ifndef NENO_UTILS_H
#define NENO_UTILS_H

#include <stdlib.h>

namespace Neno
{
	namespace Core
	{
		class Utils
		{
		public:
			static char utilsBuffer[255];
			static char* FilePath(const char* fileName);
		};
	}
}

#endif