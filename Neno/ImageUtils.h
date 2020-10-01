#pragma once
#include <GL/glut.h>
#include <FreeImage.h>
#include <iostream>

namespace neno
{
	class ImageUtils
	{
	public:
		static void LoadImage(const char* path, int* width, int* height, int* pixelSize, bool* hasAlpha, BYTE** texture, GLuint* textureId);
		static void SetImage(BYTE* texture, GLuint textureId, int width, int height, bool hasAlpha);
	};
}

