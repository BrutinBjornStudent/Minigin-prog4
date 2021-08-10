#include "MiniginPCH.h"
#include "ProjectileHitBoxComponent.h"

void ProjectileHitBoxComponent::SetPosition(float x, float y, float z)
{
	m_transform.SetPosition(x, y, z);
}

void ProjectileHitBoxComponent::SetPosition(glm::vec3 pos)
{
	m_transform.SetPosition(pos);
}
