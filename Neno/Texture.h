#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glut.h>
#include <FreeImage.h>
#include<iostream>
#include "Color.h"
#include "Utils.h"

namespace neno
{
	class Texture
	{
	private:
		GLuint textureId;
		BYTE* texture;
		bool isPNG;
	public:
		int width;
		int height;
		int pixel_size;
		Texture(const char* path);

		void Draw(int x, int y, int width, int height);
	};
}

#endif