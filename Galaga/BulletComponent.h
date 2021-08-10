#pragma once
#include "Component.h"
#include "AllComponents.h"

#include "Transform.h"

class BulletComponent :
    public BaseComponent
{
public:
	BulletComponent(glm::vec2 position, glm::vec2 directon);

	
	void Render() const override {};
	void Update(const float deltatime) override;
	void SetHitBox(ProjectileHitBoxComponent* hitbox);
	
private:
	dae::Transform m_transform;
	glm::vec3 m_Velocity;
	ProjectileHitBoxComponent* nm_pBulletHitbox;
	
};

