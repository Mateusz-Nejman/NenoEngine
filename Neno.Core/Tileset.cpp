#include "pch.h"
#include "Tileset.h"

namespace Neno
{
	namespace Core
	{
		Tileset::Tileset(const char* path, int tileWidth, int tileHeight)
		{
			ImageUtils::LoadImage(path, &this->tilesetWidth, &this->tilesetHeight, &this->pixelSize, &this->hasAlpha, &this->texture, &this->textureId, this->bitmap);
			this->tileWidth = tileWidth;
			this->tileHeight = tileHeight;
			this->rows = tilesetHeight / tileHeight;
			this->columns = tilesetWidth / tileWidth;
		}

		Tileset::~Tileset()
		{
			FreeImage_Unload(bitmap);
			texture = nullptr;
			bitmap = nullptr;
		}

		void Tileset::Draw(int x, int y, int tileX, int tileY, int width, int height, Color color)
		{
			glColor4d(color.r, color.g, color.b, color.a);

			ImageUtils::SetImage(texture, textureId, this->tilesetWidth, this->tilesetHeight, hasAlpha);
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
}