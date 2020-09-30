#include "Texture.h"

namespace neno
{
	Texture::Texture(const char* path)
	{
		FREE_IMAGE_FORMAT format = FreeImage_GetFileType(path, 0);

		if (format == FIF_UNKNOWN)
			format = FreeImage_GetFIFFromFilename(path);

		FIBITMAP* image = FreeImage_Load(format, path);

		width = FreeImage_GetWidth(image);
		height = FreeImage_GetHeight(image);
		pixel_size = FreeImage_GetBPP(image);

		isPNG = FreeImage_GetColorType(image) == FIC_RGBALPHA;
		texture = (BYTE*)FreeImage_GetBits(image);
		GLuint idTest;
		glGenTextures(1, &idTest);
		textureId = idTest;
	}

	void Texture::Draw(int x, int y, int width, int height, Color color)
	{
		glColor4d(color.r, color.g, color.b, color.a);

		glBindTexture(GL_TEXTURE_2D, textureId);
		if(isPNG)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, texture);
		else
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, texture);
		glEnable(GL_TEXTURE_2D);
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