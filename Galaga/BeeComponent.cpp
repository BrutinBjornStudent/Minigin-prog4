#include "BeeComponent.h"

#include <iostream>

void BeeComponent::Update(const float deltatime)
{
	if (nm_SpriteManager)
	{		
		m_SpriteElapsedTime += deltatime;
		if (m_SpriteElapsedTime >= m_NextSpriteTreshhold)
		{
			m_SpriteElapsedTime -= m_NextSpriteTreshhold;
			std::cout << "next sprite triggered" << std::endl;
			nm_SpriteManager->NextSpriteX();
		}
	}
	
}
