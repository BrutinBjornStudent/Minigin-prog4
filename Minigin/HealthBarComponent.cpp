#include "MiniginPCH.h"
#include "HealthBarComponent.h"

#include "ResourceManager.h"


HealthBarComponent::HealthBarComponent(HealthComponent* healthref)
	:nm_pHealthComp(healthref)
	,m_Size(10, 10)
{
}

void HealthBarComponent::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

void HealthBarComponent::SetDirection(Direction direction)
{
	m_direction = direction;
}

void HealthBarComponent::SetSize(glm::vec2 size)
{
	m_Size = size;
}


void HealthBarComponent::SetTexture(const std::string& filename)
{

	delete m_pTexture;
	m_pTexture = dae::ResourceManager::GetInstance().LoadTexture(filename);
}

void HealthBarComponent::SetTexture(dae::Texture2D* texture2D)
{

	delete m_pTexture;
	m_pTexture = texture2D;
}
