#include "ApplicationConfig.h"

namespace neno
{
	ApplicationConfig::ApplicationConfig(int screenWidth, int screenHeight, bool allowFullscreen, Color clearBufferColor) {
		this->screenWidth = screenWidth;
		this->screenHeight = screenHeight;
		this->allowFullscreen = allowFullscreen;
		this->clearBufferColor = clearBufferColor;
	}
}