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
		
		bool _hasAlpha = FreeImage_GetColorType(image) == FIC_RGBALPHA;
		GLuint _textureId;

		image = FreeImage_ConvertTo24Bits(image);
		BYTE* _texture = (BYTE*)FreeImage_GetBits(image);

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
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, texture);
		else
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, texture);
	}
}