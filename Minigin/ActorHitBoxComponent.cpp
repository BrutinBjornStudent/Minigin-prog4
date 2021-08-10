#include "MiniginPCH.h"
#include "ActorHitBoxComponent.h"

void ActorHitBoxComponent::SetPosition(float x, float y, float z)
{
	m_transform.SetPosition(x, y, z);
}

void ActorHitBoxComponent::SetPosition(glm::vec3 pos)
{
	m_transform.SetPosition(pos);
}
