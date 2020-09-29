#include "Tileset.h"

namespace neno
{
	Tileset::Tileset(const char* path, int tileWidth, int tileHeight)
	{
		FREE_IMAGE_FORMAT format = FreeImage_GetFileType(path, 0);

		if (format == FIF_UNKNOWN)
			format = FreeImage_GetFIFFromFilename(path);

		FIBITMAP* image = FreeImage_Load(format, path);

		this->tilesetWidth = FreeImage_GetWidth(image);
		this->tilesetHeight = FreeImage_GetHeight(image);
		this->tileWidth = tileWidth;
		this->tileHeight = tileHeight;
		this->rows = tilesetHeight / tileHeight;
		this->columns = tilesetWidth / tileWidth;
		pixel_size = FreeImage_GetBPP(image);
		
		isPNG = FreeImage_GetColorType(image) == FIC_RGBALPHA;
		texture = (BYTE*)FreeImage_GetBits(image);
		GLuint idTest;
		glGenTextures(1, &idTest);
		textureId = idTest;
	}

	void Tileset::Draw(int x, int y, int tileX, int tileY, int width, int height, Color color)
	{
		glColor4d(color.r, color.g, color.b, color.a);

		glBindTexture(GL_TEXTURE_2D, textureId);
		if (isPNG)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->tilesetWidth, this->tilesetHeight, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, texture);
		else
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->tilesetWidth, this->tilesetHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, texture);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);

		tileY = rows - 1 - tileY;
		double _baseX = 1.0 / (double)columns;
		double _baseY = 1.0 / (double)rows;
		double _x = _baseX * (double)tileX;
		double _y = _baseY * (double)tileY;

		glTexCoord2d(_x, _y);
		glVertex2d(x, y);
		glTexCoord2d(_x + _baseX, _y);
		glVertex2d(x + width, y);
		glTexCoord2d(_x + _baseX, _y + _baseY);
		glVertex2d(x + width, y + height);
		glTexCoord2d(_x, _y + _baseY);
		glVertex2d(x, y + height);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glFlush();
	}
}