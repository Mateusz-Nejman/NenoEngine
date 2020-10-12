#include "pch.h"
#include "Sound.h"

namespace Neno
{
	namespace Core
	{
		irrklang::ISoundEngine* Sound::soundEngine = nullptr;

		Sound::~Sound()
		{
			sound->drop();
			sound = nullptr;
		}

		Sound::Sound(const char* filepath)
		{
			if (soundEngine == nullptr)
			{
				soundEngine = irrklang::createIrrKlangDevice();

				if (!soundEngine)
					std::cout << "Unable to create sound device" << std::endl;
			}

			sound = soundEngine->play2D(filepath, false, true);
		}

		void Sound::Play(bool looped)
		{
			sound->setIsLooped(looped);
			sound->setIsPaused(false);
		}

		void Sound::Pause()
		{
			sound->setIsPaused(true);
		}

		bool Sound::IsPlayed()
		{
			return !sound->getIsPaused();
		}

		void Sound::Dispose()
		{
			if (soundEngine != nullptr)
			{
				soundEngine->drop();
				soundEngine = nullptr;
			}
		}
	}
}