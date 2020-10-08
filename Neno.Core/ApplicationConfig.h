#ifndef NENO_APPLICATION_CONFIG_H
#define NENO_APPLICATION_CONFIG_H

#include "Color.h"

namespace Neno
{
	namespace Core
	{
		class ApplicationConfig
		{
		public:
			int screenWidth;
			int screenHeight;
			bool allowFullscreen;
			bool debugMode;
			const char* title;
			Color* clearBufferColor;

			~ApplicationConfig();
			ApplicationConfig(const char* title, int screenWidth, int screenHeight, bool allowFullscreen, bool debugMode, Color* clearBufferColor);
			void Dispose();
		};
	}
}

#endif