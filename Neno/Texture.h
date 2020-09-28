#pragma once
#include <GL/glut.h>
#include <FreeImage.h>
#include<iostream>
#include "Color.h"
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
		}

		void Draw(int x, int y, int width, int height)
		{
			glColor3d(Color::White.r, Color::White.g, Color::White.b);
			
			glBindTexture(GL_TEXTURE_2D, textureId);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture);
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
	};
}
