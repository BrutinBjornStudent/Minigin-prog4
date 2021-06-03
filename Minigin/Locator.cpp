#include "MiniginPCH.h"
#include "Locator.h"


SoundSystem* Locator::_ss_instance = &m_defaultSS;
NullSoundSystem Locator::m_defaultSS;