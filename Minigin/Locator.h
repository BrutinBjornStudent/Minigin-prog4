#pragma once
#include "SoundSystem.h"


class Locator final
{

	static SoundSystem* _ss_instance;
	static NullSoundSystem m_defaultSS;

public:


	static void CloseSoundSystem()
	{
		delete _ss_instance;
	}
	static SoundSystem& GetSoundSystem() { return *_ss_instance; }
	static void RegisterSoundSystem(SoundSystem* ss)
	{

		if (ss == nullptr)
			_ss_instance = &m_defaultSS;
		else
			_ss_instance = ss;
	}
};

