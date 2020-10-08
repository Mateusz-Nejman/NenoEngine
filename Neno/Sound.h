#pragma once
#include <irrKlang.h>
#include <iostream>

namespace neno
{
	class Sound
	{
	private:
		static irrklang::ISoundEngine* soundEngine;
		irrklang::ISound* sound;
	public:
		Sound(const char* path);
		~Sound();
		void Play(bool looped = false);
		void Pause();
		bool IsPlayed();
		static void Dispose();
	};
}