#include "TestEngine.h"
#include <iostream>

namespace neno
{
	TestEngine::TestEngine()
	{
		x = 0;
		y = 320;
		simpleTexture = new Texture(Utils::FilePath("Content/image.bmp"));
		simpleSprite = new Sprite(simpleTexture);
		simpleSprite->originX = 16;
		simpleSprite->originY = 16;
		simpleSprite->color = Color::Red.Clone();
		simpleSprite->scaleX = 2;
		simpleSprite->scaleY = 1.5;

		points.push_back(0);
		points.push_back(0);
		points.push_back(100);
		points.push_back(28);
		points.push_back(0);
		points.push_back(256);

		simpleTileset = new Tileset(Utils::FilePath("Content/simpleTileset1.png"), 32, 32);
	}

	void TestEngine::Update(float framesPerSecond)
	{
		if (Keyboard::IsDown(NENO_KEY_UP))
			simpleSprite->y += 5;

		if (Keyboard::IsDown(NENO_KEY_DOWN))
			simpleSprite->y -= 5;

		if (Keyboard::IsDown(NENO_KEY_LEFT))
			simpleSprite->x -= 5;

		if (Keyboard::IsDown(NENO_KEY_RIGHT))
			simpleSprite->x += 5;

		if (Keyboard::IsDown(' '))
		{
			simpleSprite->x += 5;
			simpleSprite->y -= 5;
		}

		if (Keyboard::IsPressed('a'))
			simpleSprite->x += 20;

		if (Keyboard::IsPressed('q'))
			simpleSprite->color->r = 0;

		if (Keyboard::IsPressed('w'))
			simpleSprite->angle += 45;
	}

	void TestEngine::Render()
	{
		Primitives::DrawRectangleOutline(5, 5, 256, 256, 3, Color::Black);
		Primitives::DrawRectangleOutline(271, 5, 256, 256, 3, Color::Black);

		simpleTileset->Draw(10, 128, 0, 0, 32, 32, Color::White);
		simpleTileset->Draw(42, 128, 0, 1, 32, 32, Color::White);
		simpleTileset->Draw(74, 128, 1, 0, 32, 32, Color::White);
		simpleTileset->Draw(106, 128, 1, 1, 32, 32, Color::White);

		simpleSprite->Draw();
		simpleTexture->Draw(128, 128, 32, 32);
	}

	void TestEngine::Resize(int width, int height)
	{

	}
}
