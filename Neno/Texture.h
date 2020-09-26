#pragma once
#include <GL/glut.h>
#include <FreeImage.h>
#include<iostream>
namespace neno
{
	class Texture
	{
	private:
		GLuint textureId;
		BYTE* texture;
	public:
		int width;
		int height;
		int pixel_size;
		Texture(const char* path)
		{
			FREE_IMAGE_FORMAT format = FreeImage_GetFileType(path, 0);
			std::cout << "Format: " << format << std::endl;

			if (format == FIF_UNKNOWN)
				format = FreeImage_GetFIFFromFilename(path);
			FIBITMAP* image = FreeImage_Load(format, path);

			if (image == nullptr)
				std::cout << "nullptr" << std::endl;
			width = FreeImage_GetWidth(image);
			height = FreeImage_GetHeight(image);
			pixel_size = FreeImage_GetBPP(image);

			std::cout << width << "x" << height << "x" << pixel_size <<  std::endl;

			texture = (BYTE*)FreeImage_GetBits(image);
			GLuint idTest;
			glGenTextures(1, &idTest);
			textureId = idTest;
			
			std::cout << "textureId for " << path << ":" << idTest << std::endl;
		}

		void Draw(int x, int y, int width, int height)
		{
			glBindTexture(GL_TEXTURE_2D, textureId);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, (GLvoid*)texture);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			//glDisable(GL_TEXTURE_2D);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(x, y, 0.0);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(x+width, y, 0.0);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(x+width, y+height, 0.0);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(x, y+height, 0.0);
			glEnd();
			glFlush();
		}
	};
}
