#include "TestEngine.h"

namespace Neno
{
	TestEngine::~TestEngine()
	{
		delete texBmp;
		delete texPng;
		delete texTPng;
		delete simpleTexture;
		delete simpleSprite;
		delete simpleFont;
		delete simpleTileset;
		delete mainMusic;

		texBmp = nullptr;
		texPng = nullptr;
		texTPng = nullptr;
		simpleTexture = nullptr;
		simpleSprite = nullptr;
		simpleFont = nullptr;
		simpleTileset = nullptr;
		mainMusic = nullptr;
	}

	TestEngine::TestEngine()
	{
		
	}

	void TestEngine::Create()
	{
		texBmp = new Texture(Utils::FilePath("Content/Graphics/image.bmp"));
		texPng = new Texture(Utils::FilePath("Content/Graphics/image.png"));
		texTPng = new Texture(Utils::FilePath("Content/Graphics/transparent1.png"));
		simpleTexture = new Texture(Utils::FilePath("Content/Graphics/image.bmp"));
		simpleSprite = new Sprite(simpleTexture);

		simpleSprite->originX = 16;
		simpleSprite->originY = 16;
		simpleSprite->color = Color::Red.Clone();
		simpleSprite->scaleX = 2;
		simpleSprite->scaleY = 1.5;

		simpleFont = new Font(Utils::FilePath("Content/Fonts/Roboto-Black.ttf"), 24,32,381);

		simpleTileset = new Tileset(Utils::FilePath("Content/Graphics/simpleTileset1.png"), 32, 32);

		mainMusic = new Sound(Utils::FilePath("Content/Audio/Korobeiniki.wav"));
	}

	void TestEngine::Update(float framesPerSecond)
	{
		if (!mainMusic->IsPlayed())
			mainMusic->Play(false);
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
		texBmp->Draw(320, 128, 32, 32);
		texPng->Draw(357, 128, 32, 32);
		texTPng->Draw(357+37, 128, 32, 32);
		simpleTexture->Draw(357 + 37 + 37, 128, 32, 32);

		//simpleFont->Draw("Test", 256, 256, Color::Blue);
		simpleFont->Draw(L"Zażółć gęślą jaźń", 10, Application::currentConfig->screenHeight-50, Color::White);
	}

	void TestEngine::Resize(int width, int height)
	{

	}
}
