#include "MiniginPCH.h"
#include "RenderComponent.h"
#include "ResourceManager.h"


void RenderComponent::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
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

