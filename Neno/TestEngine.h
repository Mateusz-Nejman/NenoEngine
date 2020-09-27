#pragma once
#include "Engine.h"
#include "Primitives.h"
#include "Texture.h"
#include "Keyboard.h"
#include "Mouse.h"

namespace neno
{
	class TestEngine :
		public Engine
	{
		Texture* simpleTexture;
		Texture* simpleTexture1;
		int x, y;
	public:
		TestEngine()
		{
			x = 0;
			y = 320;
			char basePath[255] = "";
			char basePath1[255] = "";
			std::cout << _fullpath(basePath, "image.png", sizeof(basePath));
			std::cout << _fullpath(basePath1, "image.bmp", sizeof(basePath1));
			simpleTexture = new Texture(_fullpath(basePath, "image.png", sizeof(basePath)));
			simpleTexture1 = new Texture(_fullpath(basePath1, "image.bmp", sizeof(basePath1)));
		}

		void Update()
		{
			if(Keyboard::IsPressed('a'))
				x += 5;

			if (Mouse::LeftPressed())
				y += 1;
		}

		void Render()
		{
			Color color(255, 0, 0);
			Primitives::DrawRectangle(0, 0, 32, 32, color);
			simpleTexture->Draw(x, y, 32, 32);
			Primitives::DrawRectangle(32, 0, 32, 32, color);
			simpleTexture->Draw(32, 32, 32, 32);
			Primitives::DrawTriangle(0, 0, 256, 256, 256, 0, color);
			
		}

		void Resize(int width, int height)
		{

		}
	};
}
