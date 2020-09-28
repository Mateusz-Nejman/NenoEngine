#ifndef ENGINE_H
#define ENGINE_H

namespace neno
{
	class Engine
	{
	public:
		virtual void Update(float framesPerSecond);

		virtual void Render();

		virtual void Resize(int width, int height);
	};
}

#endif