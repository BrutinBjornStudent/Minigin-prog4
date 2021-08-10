#include "BulletComponent.h"

void BulletComponent::Update(const float deltatime)
{
	//add veloctiy;
	glm::vec3 newpos = m_transform.GetPosition();

	newpos += m_Velocity * deltatime;
	m_transform.SetPosition(newpos);
	if (nm_pBulletHitbox)
	{
		nm_pBulletHitbox;
	}

	
}

void BulletComponent::SetHitBox(ProjectileHitBoxComponent* hitbox)
{
	nm_pBulletHitbox = hitbox;

	
}
