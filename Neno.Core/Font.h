#ifndef NENO_FONT_H
#define NENO_FONT_H
#pragma once
#include <ft2build.h>
#include <GL/glew.h>
#include <map>
#include <string>
#include <vector>
#include "Color.h"
#include "ImageUtils.h"
#include FT_FREETYPE_H 

namespace Neno
{
	namespace Core
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
			std::map<unsigned int, Character> characters;
		public:
			~Font();
			Font(const char* filepath, int size, int firstChar = 32, int lastChar = 255);
			void Draw(std::wstring text, int x, int y, Color color);
			void DrawMultiColor(std::wstring text, int x, int y, std::vector<Color*> colors);
			int GetSize();
			static void Dispose();
		};
	}
}
#endif