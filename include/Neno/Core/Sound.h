#pragma once
#ifndef NENO_SOUND_H
#define NENO_SOUND_H

#include <irrKlang.h>
#include <iostream>

namespace Neno
{
	namespace Core
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
			static void Initialize();
			static void Dispose();
		};
	}
}

#endif