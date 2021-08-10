#include "BeeComponent.h"

void BeeComponent::Update(const float deltatime)
{
	m_SpriteElapsedTime += deltatime;
	if (m_SpriteElapsedTime <= m_NextSpriteTreshhold)
	{
		m_SpriteElapsedTime -= m_NextSpriteTreshhold;
		nm_SpriteManager->SetXSprite(+1);
		
	}
	
	
}
