#include <Neno/Core/Neno.h>

using namespace Neno::Core;

namespace Neno
{
	class TestEngine : public Engine
	{
	private:
		Texture* simpleTexture;
		Texture* texBmp;
		Texture* texPng;
		Texture* texTPng;
		Sprite* simpleSprite;
		Tileset* simpleTileset;
		Font* simpleFont;
		Sound* mainMusic;
	public:
		~TestEngine();

		TestEngine();

		void Create();

		void Update(float framesPerSecond);

		void Render();

		void Resize(int width, int height);
	};
}
