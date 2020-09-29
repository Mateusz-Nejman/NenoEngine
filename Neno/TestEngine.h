#pragma once
#include "Neno.h"
#include <vector>

namespace neno
{
	class TestEngine :
		public Engine
	{
		Texture* simpleTexture;
		Sprite* simpleSprite;
		Tileset* simpleTileset;
		int x, y;
		std::vector<int> points;
	public:
		TestEngine();

		void Update(float framesPerSecond);

		void Render();

		void Resize(int width, int height);
	};
}
