#ifndef APPLICATION_CONFIG_H
#define APPLICATION_CONFIG_H

#include "Color.h"

namespace neno
{
	class ApplicationConfig
	{
	public:
		int screenWidth;
		int screenHeight;
		bool allowFullscreen;
		bool debugMode;
		Color* clearBufferColor;

		~ApplicationConfig();
		ApplicationConfig(int screenWidth, int screenHeight, bool allowFullscreen, bool debugMode, Color* clearBufferColor);
		void Dispose();
	};
}

#endif