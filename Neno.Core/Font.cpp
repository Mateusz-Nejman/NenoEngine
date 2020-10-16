#include "pch.h"
#include "Font.h"
#include <iostream>

namespace Neno
{
    namespace Core
    {
        FT_Library* Font::freeTypeLibrary = nullptr;
        Font::~Font()
        {
            for (int a = 0; a < characters.size(); a++)
            {
                glDeleteTextures(1, &characters[a].TextureID);
                delete characters[a].Texture;
            }

            characters.clear();
        }
        Font::Font(const char* filepath, int size, int firstChar, int lastChar)
        {
            FT_New_Face(*freeTypeLibrary, filepath, 0, &face);
            FT_Set_Pixel_Sizes(face, 0, size);

            for (unsigned int c = firstChar; c < lastChar; c++)
            {

                if (FT_Load_Char(face, c, FT_LOAD_RENDER))
                {
                    continue;
                }

                unsigned int texture;
                glGenTextures(1, &texture);

                Character character = {
                    texture,
                    face->glyph->bitmap.width, face->glyph->bitmap.rows,
                    face->glyph->bitmap_left, face->glyph->bitmap_top,
                    face->glyph->advance.x,
					ImageUtils::ConvertTTFToTransparent(face->glyph->bitmap.buffer, face->glyph->bitmap.width, face->glyph->bitmap.rows)
                };

                characters.insert(std::pair<unsigned int, Character>(c, character));
            }

            this->size = size;

            FT_Done_Face(face);
        }

        void Font::Draw(std::wstring text, int x, int y, Color color)
        {
            glColor4d(color.r, color.g, color.b, color.a);

            std::wstring::const_iterator c;
            for (c = text.begin(); c != text.end(); c++)
            {

                Character ch = characters[*c];
                float xpos = x + ch.OffsetX;
                float ypos = y - (ch.Height - ch.OffsetY);

                float w = ch.Width;
                float h = ch.Height;
                glBindTexture(GL_TEXTURE_2D, ch.TextureID);

                glTexImage2D(
                    GL_TEXTURE_2D,
                    0,
                    GL_RGBA,
                    ch.Width,
                    ch.Height,
                    0,
                    GL_RGBA,
                    GL_UNSIGNED_BYTE,
                    ch.Texture
                );

                glEnable(GL_TEXTURE_2D);

                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

                glBegin(GL_QUADS);
                glTexCoord2d(0.0, 0.0);
                glVertex2d(xpos, ypos + h);
                glTexCoord2d(1.0, 0.0);
                glVertex2d(xpos + w, ypos + h);
                glTexCoord2d(1.0, 1.0);
                glVertex2d(xpos + w, ypos);
                glTexCoord2d(0.0, 1.0);
                glVertex2d(xpos, ypos);
                glEnd();
                glDisable(GL_TEXTURE_2D);
                x += (ch.Advance >> 6);
            }

            glFlush();
        }

        void Font::Draw(std::string text, int x, int y, Color color)
        {
            glColor4d(color.r, color.g, color.b, color.a);

            std::string::const_iterator c;
            for (c = text.begin(); c != text.end(); c++)
            {

                Character ch = characters[*c];
                float xpos = x + ch.OffsetX;
                float ypos = y - (ch.Height - ch.OffsetY);

                float w = ch.Width;
                float h = ch.Height;
                glBindTexture(GL_TEXTURE_2D, ch.TextureID);

                glTexImage2D(
                    GL_TEXTURE_2D,
                    0,
                    GL_RGBA,
                    ch.Width,
                    ch.Height,
                    0,
                    GL_RGBA,
                    GL_UNSIGNED_BYTE,
                    ch.Texture
                );

                glEnable(GL_TEXTURE_2D);

                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

                glBegin(GL_QUADS);
                glTexCoord2d(0.0, 0.0);
                glVertex2d(xpos, ypos + h);
                glTexCoord2d(1.0, 0.0);
                glVertex2d(xpos + w, ypos + h);
                glTexCoord2d(1.0, 1.0);
                glVertex2d(xpos + w, ypos);
                glTexCoord2d(0.0, 1.0);
                glVertex2d(xpos, ypos);
                glEnd();
                glDisable(GL_TEXTURE_2D);
                x += (ch.Advance >> 6);
            }

            glFlush();
        }

        void Font::DrawMultiColor(std::wstring text, int x, int y, std::vector<Color*> colors)
        {
            std::wstring::const_iterator c;
            int colorIndex = 0;
            for (c = text.begin(); c != text.end(); c++)
            {
                Character ch = characters[*c];
                Color color = *colors[colorIndex];
                glColor4d(color.r, color.g, color.b, color.a);
                float xpos = x + ch.OffsetX;
                float ypos = y - (ch.Height - ch.OffsetY);

                float w = ch.Width;
                float h = ch.Height;
                glBindTexture(GL_TEXTURE_2D, ch.TextureID);

                glTexImage2D(
                    GL_TEXTURE_2D,
                    0,
                    GL_RGBA,
                    ch.Width,
                    ch.Height,
                    0,
                    GL_RGBA,
                    GL_UNSIGNED_BYTE,
                    ch.Texture
                );
                glEnable(GL_TEXTURE_2D);

                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

                glBegin(GL_QUADS);
                glTexCoord2d(0.0, 0.0);
                glVertex2d(xpos, ypos + h);
                glTexCoord2d(1.0, 0.0);
                glVertex2d(xpos + w, ypos + h);
                glTexCoord2d(1.0, 1.0);
                glVertex2d(xpos + w, ypos);
                glTexCoord2d(0.0, 1.0);
                glVertex2d(xpos, ypos);
                glEnd();
                glDisable(GL_TEXTURE_2D);
                glFlush();
                x += (ch.Advance >> 6);
                colorIndex++;
            }
        }

        void Font::Initialize()
        {
            freeTypeLibrary = new FT_Library();
            FT_Init_FreeType(freeTypeLibrary);
        }

        void Font::Dispose()
        {
            if (freeTypeLibrary != nullptr)
            {
                FT_Done_FreeType(*freeTypeLibrary);

                delete freeTypeLibrary;
            }
        }

        int Font::GetSize()
        {
            return this->size;
        }
    }
}