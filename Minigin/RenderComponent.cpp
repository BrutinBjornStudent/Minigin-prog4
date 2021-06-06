#include "MiniginPCH.h"
#include "RenderComponent.h"
#include "ResourceManager.h"


void RenderComponent::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

void RenderComponent::SetSize(float x, float y)
{
	if (x >1.f && y > 1.f)
	{
		m_IsSizeSet = true;
	}
	else
	{
		m_IsSizeSet = false;
	}
	m_Size.x = x;
	m_Size.y = y;
}

void RenderComponent::SetOffset(int x, int y)
{

	m_offset.x = float(x);
	m_offset.y = float(y);
}

void RenderComponent::SetTexture(const std::string& filename)
{
	if (m_pTexture)
		delete m_pTexture;
	m_pTexture = dae::ResourceManager::GetInstance().LoadTexture(filename);
}

void RenderComponent::SetTexture(dae::Texture2D* texture2D)
{
	if (m_pTexture)
		delete m_pTexture;
	m_pTexture = texture2D;
}

void RenderComponent::SetSourceRect(SDL_Rect rect)
{

	delete m_pSrcRect;
	m_pSrcRect = new SDL_Rect{rect.x,rect.y,rect.w,rect.h};
}

