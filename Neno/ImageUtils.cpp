#include "ImageUtils.h"

namespace neno
{
	void ImageUtils::LoadImage(const char* path, int* width, int* height, int* pixelSize, bool* hasAlpha, BYTE** texture, GLuint* textureId)
	{
		FREE_IMAGE_FORMAT format = FreeImage_GetFileType(path, 0);

		if (format == FIF_UNKNOWN)
			format = FreeImage_GetFIFFromFilename(path);

		FIBITMAP* image = FreeImage_Load(format, path);
		int _width = FreeImage_GetWidth(image);
		int _height = FreeImage_GetHeight(image);
		int _pixelSize = FreeImage_GetBPP(image);
		
		bool _hasAlpha = _pixelSize == 32;
		GLuint _textureId;

		if (_hasAlpha)
		{
			image = FreeImage_ConvertTo32Bits(image);
		}
		else
		{
			image = FreeImage_ConvertTo24Bits(image);
		}
		BYTE* _texture = (BYTE*)FreeImage_GetBits(image);

		int modifier = _hasAlpha ? 4 : 3;
		for (int a = 0; a < _width * _height * modifier; a+=modifier)
		{
			BYTE b = _texture[a];
			BYTE r = _texture[a + 2];
			_texture[a] = r;
			_texture[a + 2] = b;
		}

		glGenTextures(1, &_textureId);
		*width = _width;
		*height = _height;
		*pixelSize = _pixelSize;
		*hasAlpha = _hasAlpha;
		*texture = _texture;
		*textureId = _textureId;

		/*std::cout << "Debug LoadImage " << path << std::endl;
		std::cout << "Format: " << format << std::endl;
		std::cout << "Width: " << _width << std::endl;
		std::cout << "Height: " << _height << std::endl;
		std::cout << "Pixel size: " << _pixelSize << std::endl;
		std::cout << "Color type: " << FreeImage_GetColorType(image) << std::endl;
		std::cout << "Color used: " << FreeImage_GetColorsUsed(image) << std::endl;
		std::cout << "Line width: " << FreeImage_GetLine(image) << std::endl;
		std::cout << "Palette: " << FreeImage_GetPalette(image) << std::endl;*/
	}

	void ImageUtils::SetImage(BYTE* texture, GLuint textureId, int width, int height, bool hasAlpha)
	{
		glBindTexture(GL_TEXTURE_2D, textureId);
		if (hasAlpha)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture);
		else
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture);
	}

	BYTE* ImageUtils::ConvertTTFToTransparent(unsigned char* buffer, int width, int height)
	{
		BYTE* newBuffer = new BYTE[width * height * 4];
		for (int a = 0; a < width * height * 4; a+=4)
		{
			int old = a / 4;

			if ((int)buffer[old] == 0)
			{
				newBuffer[a] = 0;
				newBuffer[a + 1] = 0;
				newBuffer[a + 2] = 0;
				newBuffer[a + 3] = 0;
			}
			else
			{
				newBuffer[a] = buffer[old];
				newBuffer[a + 1] = buffer[old];
				newBuffer[a + 2] = buffer[old];
				newBuffer[a + 3] = buffer[old];
			}
		}
		return newBuffer;
	}
}