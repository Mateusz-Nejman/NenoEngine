#pragma once
#include <ft2build.h>
#include <GL/glew.h>
#include <map>
#include <string>
#include "Color.h"
#include "ImageUtils.h"
#include FT_FREETYPE_H 

namespace neno
{
	struct Character {
		unsigned int TextureID;
		float Width, Height;
		float OffsetX, OffsetY;
		unsigned int Advance;
		BYTE* Texture;
	};

	class Font
	{
	private:
		static FT_Library* freeTypeLibrary;
		FT_Face face;
		int size;
		std::map<char, Character> characters;
	public:
		Font(const char* filepath, int size);
		void Draw(std::string text, int x, int y, Color color);
		void DrawMultiColor(std::string text, int x, int y, Color* colors);
	};

}
