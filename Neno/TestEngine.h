#pragma once
#include "Engine.h"
#include "Primitives.h"
#include "Texture.h"

namespace neno
{
	class TestEngine :
		public Engine
	{
		Texture* simpleTexture;
		Texture* simpleTexture1;
	public:
		TestEngine()
		{
			char basePath[255] = "";
			char basePath1[255] = "";
			std::cout << _fullpath(basePath, "image.png", sizeof(basePath));
			std::cout << _fullpath(basePath1, "image.bmp", sizeof(basePath1));
			simpleTexture = new Texture(_fullpath(basePath, "image.png", sizeof(basePath)));
			simpleTexture1 = new Texture(_fullpath(basePath1, "image.bmp", sizeof(basePath1)));
		}

		void Update()
		{

		}

		void Render()
		{
			Color color(255, 0, 0);
			Primitives::DrawRectangle(0, 0, 32, 32, color);
			simpleTexture->Draw(0, 32, 32, 32);
			Primitives::DrawRectangle(32, 0, 32, 32, color);
			simpleTexture->Draw(32, 32, 32, 32);
			/*for (int x = 0; x < 4; x++)
			{
				for (int y = 0; y < 4; y++)
				{
					simpleTexture->Draw(x*32, y*32, 32, 32);
				}
			}*/
			
		}

		void Resize(int width, int height)
		{

		}
	};
}
