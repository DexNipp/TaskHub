#pragma once
#include "AudioFile.h"
#include "miniaudio.h"

namespace taskhub {

	class AudioSource {
	public:
		AudioSource();
		~AudioSource();

		AudioSource(const AudioSource&) = delete;
		AudioSource& operator=(const AudioSource&) = delete;
		
		void Load(AudioFile& audioFile);    // Loads the audio file data into memory, preparing it for playback.
		void Unload();  // Unloads the audio file data from memory, releasing resources.

		void Play();
		void Pause();
		void SetLooping(bool isLooping);
		void SetCursorPosition(float seconds);  // Seeks to a specified position in the audio track.
		void SetVolume(float volume);

		float GetCursorPosition() const;
		float GetVolume() const;

		bool IsPlaying() const;
		bool IsFinished() const;
		bool IsLooping() const;
		bool IsLoaded() const { return m_IsLoaded; }  // Checks if the audio track is loaded into memory.

	private:
		std::unique_ptr<ma_sound> m_SoundHandle;

		bool m_IsLoaded = false;
	};
}