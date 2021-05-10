#include "MiniginPCH.h"
#include "RenderComponent.h"
#include "ResourceManager.h"


void RenderComponent::setPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

void RenderComponent::SetTexture(const std::string& filename)
{
	m_pTexture = dae::ResourceManager::GetInstance().LoadTexture(filename);
}

void RenderComponent::SetTexture(dae::Texture2D* texture2D)
{
	m_pTexture = texture2D;
}

