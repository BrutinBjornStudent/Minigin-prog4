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
	if (nm_pHitbox)
	{
		
		if (nm_pHitbox->IsHit())
		{
			m_BeeState = BeeStates::dying;
			nm_ParentRef.MarkForDeletion();
		}
		else
		{
			m_BeeState = BeeStates::Spawning;
		}
		
	}
	
	if (m_BeeState == BeeStates::dying)
	{
		m_BeeSubject->Notify(this);
	}
	
}
