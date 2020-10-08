#pragma once
#ifndef NENO_SPRITE_H
#define NENO_SPRITE_H

#include "Texture.h"
#include "Color.h"

namespace Neno
{
	namespace Core
	{
		class Sprite
		{
		private:
			void Initialize(Texture* texture, int x = 0, int y = 0, int width = -1, int height = -1, int originX = 0, int originY = 0, double scaleX = 1, double scaleY = 1, double angle = 0, Color* color = nullptr);
		public:
			int x;
			int y;
			int width;
			int height;
			int originX;
			int originY;
			double scaleX;
			double scaleY;
			double angle;
			Color* color;
			Texture* texture;

			~Sprite();
			Sprite(Texture* texture);
			Sprite(Texture* texture, int x, int y);
			Sprite(Texture* texture, int x, int y, int width, int height);
			Sprite(Texture* texture, int x, int y, int width, int height, int originX, int originY);
			Sprite(Texture* texture, int x, int y, int width, int height, int originX, int originY, double scaleX, double scaleY);
			Sprite(Texture* texture, int x, int y, int width, int height, int originX, int originY, double scaleX, double scaleY, double angle);
			Sprite(Texture* texture, int x, int y, int width, int height, int originX, int originY, double scaleX, double scaleY, double angle, Color* color);

			void Draw();
		};
	}
}

#endif