#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <FreeImage.h>
#include "Color.h"
#include "Utils.h"
#include "ImageUtils.h"

namespace neno
{
	class Texture
	{
	private:
		GLuint textureId;
		BYTE* texture;
		bool hasAlpha;
		FIBITMAP* bitmap;
	public:
		int width;
		int height;
		int pixelSize;
		Texture(const char* path);
		~Texture();

		void Draw(int x, int y, int width, int height, Color color = Color::White);
	};
}

#endif