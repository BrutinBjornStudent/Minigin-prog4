#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <map>
#include <mutex>
#include <thread>


struct playSound
{
	int id;
	int volume;
};




class SoundSystem // this is a singleton design
{


	//constructs
public:
	SoundSystem() = default;
	virtual ~SoundSystem() = default;
	virtual void play(unsigned short id, const int volume) = 0;
	virtual void loadSound(int id, const std::string source) = 0;
};	



class SDLSoundSystem final : public SoundSystem
{
public:

	
	//void PlaySound(int id, int volume) override
	//{
	//	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	//	int channel = Mix_PlayMusic(m_Songs[id],-1);
	//	Mix_Volume(channel, volume);
	//}
	SDLSoundSystem() : SoundSystem()
	{
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
			std::cout << "Error" << Mix_GetError << std::endl;
		else
			std::cout << "SDL mix started" << std::endl;
	}

	~SDLSoundSystem()
	{
		Mix_CloseAudio();
		Mix_Quit();
	}
	
	void loadSound(int id,const std::string source) override
	{


		std::string fullpath = "../Data/music/";
		fullpath.append(source);

		
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
			std::cout << "Error" << Mix_GetError << std::endl;
		else
			std::cout << "SDL mix started" << std::endl;
		
		Mix_Music* music = Mix_LoadMUS(fullpath.c_str());
		if (music != nullptr)
		{
			m_Songs[id] = music;
			std::cout << "music loaded at: " << id << std::endl;
		}
		else
		std::cout << "no music found at: " << fullpath << " error: " << Mix_GetError << std::endl;
	}
	//void StopSound(int channel) override
	//{
	//	Mix_Pause(channel);
	//	
	//}
	//void stopAllSounds() override
	//{
	//	Mix_PauseMusic();
	//}
	void play(const unsigned short id, const int volume) override
	{
		Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
		int channel = Mix_PlayMusic(m_Songs[id],-1);
		Mix_Volume(channel, volume);
	};
private:

	//std::map<int, Mix_Chunk*> m_effects;
	std::map<int, Mix_Music*> m_Songs;

	//std::thread m_soundthread;
};


class NullSoundSystem final : public SoundSystem
{
	void play(unsigned short, const int ) override {};
	void loadSound(int , const std::string ) override {};
};



