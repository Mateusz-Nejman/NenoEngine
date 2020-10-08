#pragma once
#include "Neno.h"
#include <vector>

namespace neno
{
	class TestEngine :
		public Engine
	{
		Texture* simpleTexture;
		Texture* texBmp;
		Texture* texPng;
		Texture* texTPng;
		Sprite* simpleSprite;
		Tileset* simpleTileset;
		Font* simpleFont;
		Sound* mainMusic;
	public:
		TestEngine();
		~TestEngine();

		void Create();

		void Update(float framesPerSecond);

		void Render();

		void Resize(int width, int height);
	};
}
