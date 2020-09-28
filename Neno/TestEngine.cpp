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
		simpleSprite->Draw();
		simpleTexture->Draw(128, 128, 32, 32);
		Primitives::DrawRectangle(10, 530, 100, 20, Color::Transparent);
		Primitives::DrawTriangle(110, 600, 110, 480, 200, 540, Color::Red);
	}

	void TestEngine::Resize(int width, int height)
	{

	}
}
