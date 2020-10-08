#include "pch.h"
#include "ApplicationConfig.h"

namespace Neno
{
	namespace Core
	{
		ApplicationConfig::~ApplicationConfig()
		{
			clearBufferColor = nullptr;
		}
		ApplicationConfig::ApplicationConfig(const char* title, int screenWidth, int screenHeight, bool allowFullscreen, bool debugMode, Color* clearBufferColor) {
			this->screenWidth = screenWidth;
			this->screenHeight = screenHeight;
			this->allowFullscreen = allowFullscreen;
			this->clearBufferColor = clearBufferColor;
			this->debugMode = debugMode;
			this->title = title;
		}

		void ApplicationConfig::Dispose()
		{

		}
	}
}