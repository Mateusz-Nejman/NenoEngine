#pragma once
#include "Neno.h"

namespace neno
{
	class TestEngine :
		public Engine
	{
		Texture* simpleTexture;
		Sprite* simpleSprite;
		int x, y;
	public:
		TestEngine();

		void Update(float framesPerSecond);

		void Render();

		void Resize(int width, int height);
	};
}
