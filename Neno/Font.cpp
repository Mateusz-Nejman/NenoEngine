#include "Font.h"

namespace neno
{
    FT_Library* Font::freeTypeLibrary = nullptr;
	Font::Font(const char* filepath, int size)
	{
		if (freeTypeLibrary == nullptr)
		{
            freeTypeLibrary = new FT_Library();
			FT_Init_FreeType(freeTypeLibrary);
		}

		FT_New_Face(*freeTypeLibrary, filepath, 0, &face);
		FT_Set_Pixel_Sizes(face, 0, size);

        for (unsigned char c = 32; c < 255; c++)
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
            characters.insert(std::pair<char, Character>(c, character));
        }
	}

    void Font::Draw(std::string text, int x, int y, Color color)
    {
        glColor4d(color.r, color.g, color.b, color.a);

        std::string::const_iterator c;
        for (c = text.begin(); c != text.end(); c++)
        {
            Character ch = characters[*c];
            FT_Load_Char(face, *c, FT_LOAD_RENDER);
            float xpos = x + ch.OffsetX;
            float ypos = y - (ch.Height - ch.OffsetY);

            float w = ch.Width;
            float h = ch.Height;
            glBindTexture(GL_TEXTURE_2D, ch.TextureID);

            glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RGBA,
                face->glyph->bitmap.width,
                face->glyph->bitmap.rows,
                0,
                GL_RGBA,
                GL_UNSIGNED_BYTE,
                ch.Texture
            );
            glEnable(GL_TEXTURE_2D);
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
        }
    }

    void Font::DrawMultiColor(std::string text, int x, int y, Color* colors)
    {
        std::string::const_iterator c;
        int colorIndex = 0;
        for (c = text.begin(); c != text.end(); c++)
        {
            Character ch = characters[*c];
            Color color = colors[colorIndex];
            glColor4d(color.r, color.g, color.b, color.a);
            FT_Load_Char(face, *c, FT_LOAD_RENDER);
            float xpos = x + ch.OffsetX;
            float ypos = y - (ch.Height - ch.OffsetY);

            float w = ch.Width;
            float h = ch.Height;
            glBindTexture(GL_TEXTURE_2D, ch.TextureID);

            glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RGBA,
                face->glyph->bitmap.width,
                face->glyph->bitmap.rows,
                0,
                GL_RGBA,
                GL_UNSIGNED_BYTE,
                ch.Texture
            );
            glEnable(GL_TEXTURE_2D);
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
}