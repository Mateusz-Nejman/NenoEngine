#ifndef NENO_ENGINE_H
#define NENO_ENGINE_H

namespace Neno
{
	namespace Core
	{
		class Engine
		{
		public:
			virtual void Create();

			virtual void Update(float framesPerSecond);

			virtual void Render();

			virtual void Resize(int width, int height);
		};
	}
}

#endif