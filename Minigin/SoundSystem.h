#pragma once
#include <algorithm>
#include <list>
#include <SDL.h>
#include <SDL_mixer.h>
#include <map>
#include <mutex>
#include <stack>
#include <thread>


struct PlaySound
{
	int m_id;
	float m_volume;
	std::string m_filename;
};




class SoundSystem // this is a singleton design
{


	//constructs
public:
	SoundSystem() = default;
	virtual ~SoundSystem() = default;
	virtual void play( unsigned short id, float volume, const std::string& fileName) = 0;
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

		m_thread = std::thread([this]() {this->Update(); });
	}

	~SDLSoundSystem()
	{
		m_SoundQueue.clear();

		Mix_CloseAudio();
		Mix_Quit();

		m_stopping = true;
		m_thread.join();





	}
	
	void loadSound(int id,const std::string source) override
	{

		std::string fullpath = "../Data/music/";
		fullpath.append(source);
		
		
		Mix_Music* music = Mix_LoadMUS(fullpath.c_str());
		if (music != nullptr)
		{
			m_Songs[id] = music;
			std::cout << "music loaded at: " << id << std::endl;
		}
		else
		std::cout << "no music found at: " << fullpath << " error: " << Mix_GetError << std::endl;
	}
	
	
	void play(unsigned short id, float volume, const std::string& fileName) override
	{
		float volu = std::clamp(volume, 0.f, 1.f);
		
		const PlaySound playSound{id,volu,fileName};
		std::lock_guard<std::mutex> mLock{m_Mutex};
		m_SoundQueue.push_back(playSound);
		m_WorkAvailable.notify_one();
	};

	void Update()
	{
		do
		{
			std::unique_lock<std::mutex> mlock{ m_Mutex };
			if (!m_SoundQueue.empty() && 0 == Mix_PlayingMusic())
			{
				PlaySound soundToPlay = m_SoundQueue.front();
				m_SoundQueue.pop_front();

				if (!m_isMuted)
				{
					playSound(soundToPlay.m_id, static_cast<int>(SDL_MIX_MAXVOLUME * soundToPlay.m_volume));
				}
				
			}
			if (m_SoundQueue.empty() && m_stopping)
				m_WorkAvailable.wait(mlock);

		} while (!m_stopping);
		
		std::cout << "update ended" << std::endl;
	}

private:

	void playSound(int songId, int volume) // play internal logic
	{
		int channel = Mix_PlayMusic(m_Songs[songId],1);
		Mix_Volume(channel, volume);
		std::cout << "playing music id: "<< songId <<"  on channel " << channel << std::endl;

	};

	//std::map<int, Mix_Chunk*> m_effects;

	//squeue

	std::list<PlaySound> m_SoundQueue;

	std::map<int, Mix_Music*> m_Songs;

	std::atomic_bool m_isMuted = false;
	std::atomic_bool m_stopping = false;
	//thread
	std::thread m_thread;
	std::mutex m_Mutex;
	std::condition_variable m_WorkAvailable;
};


class NullSoundSystem final : public SoundSystem
{
	void play( unsigned short, float , const std::string&) override {};
	void loadSound(int , const std::string ) override {};
};



