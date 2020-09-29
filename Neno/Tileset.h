#pragma once
#include <GL/glut.h>
#include <FreeImage.h>
#include "Color.h"

namespace neno
{
	class Tileset
	{
	private:
		GLuint textureId;
		BYTE* texture;
		bool isPNG;
	public:
		int rows;
		int columns;
		int tileWidth;
		int tileHeight;
		int tilesetWidth;
		int tilesetHeight;
		int pixel_size;

		Tileset(const char* path, int tileWidth, int tileHeight);
		void Draw(int x, int y, int tileX, int tileY, int width, int height, Color color);
	};
}

