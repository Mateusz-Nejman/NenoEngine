#include "TestEngine.h"
#include <iostream>

namespace neno
{
	TestEngine::TestEngine()
	{
		x = 0;
		y = 320;
		simpleTexture = new Texture(Utils::FilePath("Content/image.bmp"));
	}

	void TestEngine::Update(float framesPerSecond)
	{
		std::cout << framesPerSecond << std::endl;
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

	void TestEngine::Render()
	{
		simpleTexture->Draw(x, y, 32, 32);
		simpleTexture->Draw(128, 128, 64, 64);
		Primitives::DrawRectangle(10, 530, 100, 20, Color::Transparent);
		Primitives::DrawTriangle(110, 600, 110, 480, 200, 540, Color::Red);
	}

	void TestEngine::Resize(int width, int height)
	{

	}
}
