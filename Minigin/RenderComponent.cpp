#include "MiniginPCH.h"
#include "RenderComponent.h"
#include "ResourceManager.h"
#include "SDL.h"

void RenderComponent::SetPosition(float x, float y, float z)
{
	m_transform.SetPosition(x, y, z);
}

void RenderComponent::SetPosition(glm::vec3 pos)
{
	SetPosition(pos.x, pos.y,pos.z);
}


void RenderComponent::SetSize(int x, int y)
{

	m_IsSizeSet = true;

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
	SDL_QueryTexture(m_pTexture->GetSDLTexture(), nullptr, nullptr, &m_Size.x, &m_Size.y);

	
}

void RenderComponent::SetSourceRect(SDL_Rect rect)
{

	delete m_pSrcRect;
	m_pSrcRect = new SDL_Rect{rect.x,rect.y,rect.w,rect.h};
}

