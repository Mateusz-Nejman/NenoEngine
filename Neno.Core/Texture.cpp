#include "pch.h"
#include "Texture.h"

namespace Neno
{
	namespace Core
	{
		Texture::Texture(const char* path)
		{
			ImageUtils::LoadImage(path, &width, &height, &pixelSize, &hasAlpha, &texture, &textureId, bitmap);
		}

		Texture::~Texture()
		{
			FreeImage_Unload(bitmap);
			texture = nullptr;
			bitmap = nullptr;
		}

		void Texture::Draw(int x, int y, int width, int height, Color color)
		{
			glColor4d(color.r, color.g, color.b, color.a);

			ImageUtils::SetImage(texture, textureId, this->width, this->height, hasAlpha);
			glEnable(GL_TEXTURE_2D);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

			glBegin(GL_QUADS);
			glTexCoord2d(0.0, 0.0);
			glVertex2d(x, y);
			glTexCoord2d(1.0, 0.0);
			glVertex2d(x + width, y);
			glTexCoord2d(1.0, 1.0);
			glVertex2d(x + width, y + height);
			glTexCoord2d(0.0, 1.0);
			glVertex2d(x, y + height);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			glFlush();
		}
	}
}