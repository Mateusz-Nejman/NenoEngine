#ifndef NENO_IMAGEUTILS_H
#define NENO_IMAGEUTILS_H
#include <GL/glew.h>
#include <FreeImage.h>

namespace Neno
{
	namespace Core
	{
		class ImageUtils
		{
		public:
			static void LoadImage(const char* path, int* width, int* height, int* pixelSize, bool* hasAlpha, BYTE** texture, GLuint* textureId, FIBITMAP* fiBitmap);
			static void SetImage(BYTE* texture, GLuint textureId, int width, int height, bool hasAlpha);
			static BYTE* ConvertTTFToTransparent(unsigned char* buffer, int width, int height);
		};
	}
}

#endif