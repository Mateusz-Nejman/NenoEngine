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
		Color clearBufferColor;

		ApplicationConfig(int screenWidth, int screenHeight, bool allowFullscreen, Color clearBufferColor);
	};
}

#endif