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
			simpleTexture->Draw(x, y, 32, 32);
			simpleTexture->Draw(128, 128, 64, 64);
			Primitives::DrawRectangle(10, 530, 100, 20, Color::Transparent);
			Primitives::DrawTriangle(110, 600, 110, 480, 200, 540, Color::Red);
		}

		void Resize(int width, int height)
		{

		}
	};
}
