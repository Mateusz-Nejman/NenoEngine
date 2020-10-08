#pragma once
#ifndef NENO_TILESET_H
#define NENO_TILESET_H

#include <GL/glew.h>
#include <FreeImage.h>
#include "Color.h"
#include "ImageUtils.h"

namespace Neno
{
	namespace Core
	{
		class Tileset
		{
		private:
			GLuint textureId;
			BYTE* texture;
			bool hasAlpha;
			FIBITMAP* bitmap;
		public:
			int rows;
			int columns;
			int tileWidth;
			int tileHeight;
			int tilesetWidth;
			int tilesetHeight;
			int pixelSize;

			Tileset(const char* path, int tileWidth, int tileHeight);
			~Tileset();
			void Draw(int x, int y, int tileX, int tileY, int width, int height, Color color);
		};
	}
}

#endif