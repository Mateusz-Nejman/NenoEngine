#pragma once
#include "Neno.h"

namespace neno
{
	class TestEngine :
		public Engine
	{
		Texture* simpleTexture;
		int x, y;
	public:
		TestEngine()
		{
			x = 0;
			y = 320;
			simpleTexture = new Texture(Utils::FilePath("Content/image.png"));
		}

		void Update()
		{
			if (Keyboard::IsDown(NENO_KEY_UP))
				y += 5;

			if (Keyboard::IsDown(NENO_KEY_DOWN))
				y -= 5;

			if (Keyboard::IsDown(NENO_KEY_LEFT))
				x -= 5;

			if (Keyboard::IsDown(NENO_KEY_RIGHT))
				x += 5;

			if (Keyboard::IsDown(' '))
			{
				x += 5;
				y -= 5;
			}

			if (Keyboard::IsPressed('a'))
				x += 20;
		}

		void Render()
		{
			Color color1(0, 255, 128);
			Color color2(0, 128, 255);
			simpleTexture->Draw(x, y, 32, 32);
			Primitives::DrawRectangle(10, 530, 100, 20, color1);
			Primitives::DrawTriangle(110, 600, 110, 480, 200, 540, color2);
		}

		void Resize(int width, int height)
		{

		}
	};
}
