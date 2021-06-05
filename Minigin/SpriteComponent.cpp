#include "MiniginPCH.h"
#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(RenderComponent* renderRef, SDL_Rect source, int xsprites, int ysprites)
	:m_maxxSprites(xsprites)
	, m_maxySprites(ysprites)
	, nm_pRenderComp(renderRef)
	, m_spriteheight(source.h)
	, m_spritewidth(source.w)
	, m_needsUpdate(true)
	, m_source(source)
	, m_currentX(0)
	, m_currentY(0)
{

}

void SpriteComponent::Update(const float)
{
	if (m_needsUpdate)
	{

		m_source = SDL_Rect{ m_currentX * m_spritewidth, m_currentY * m_spriteheight,m_spritewidth,m_spriteheight };
		nm_pRenderComp->SetSourceRect(m_source);

		
		
	}
}

void SpriteComponent::SetXSprite(int x)
{
	m_needsUpdate = true;
	
	m_currentX = x % m_maxxSprites;
}

void SpriteComponent::setYSprite(int y)
{
	m_needsUpdate = true;
	m_currentY = y % m_maxySprites;
}


