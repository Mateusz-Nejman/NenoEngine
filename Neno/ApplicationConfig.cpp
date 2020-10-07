#include "ApplicationConfig.h"

namespace neno
{
	ApplicationConfig::~ApplicationConfig()
	{
		clearBufferColor = nullptr;
	}
	ApplicationConfig::ApplicationConfig(int screenWidth, int screenHeight, bool allowFullscreen, bool debugMode, Color* clearBufferColor) {
		this->screenWidth = screenWidth;
		this->screenHeight = screenHeight;
		this->allowFullscreen = allowFullscreen;
		this->clearBufferColor = clearBufferColor;
		this->debugMode = debugMode;
	}

	void ApplicationConfig::Dispose()
	{
		delete &screenWidth;
		delete &screenHeight;
		delete &allowFullscreen;
		delete &clearBufferColor;
		delete &debugMode;
	}
}