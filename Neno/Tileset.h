#pragma once
#include <GL/glew.h>
#include <FreeImage.h>
#include "Color.h"
#include "ImageUtils.h"

namespace neno
{
	class Tileset
	{
	private:
		GLuint textureId;
		BYTE* texture;
		bool hasAlpha;
	public:
		int rows;
		int columns;
		int tileWidth;
		int tileHeight;
		int tilesetWidth;
		int tilesetHeight;
		int pixelSize;

		Tileset(const char* path, int tileWidth, int tileHeight);
		void Draw(int x, int y, int tileX, int tileY, int width, int height, Color color);
	};
}

