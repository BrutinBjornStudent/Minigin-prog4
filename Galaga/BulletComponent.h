#pragma once
#include "Component.h"
#include "AllComponents.h"

#include "Transform.h"

class HurtboxComponent;

// Updates the position of the Texture/hurtbox.
class BulletComponent :
    public BaseComponent
{
public:
	BulletComponent(glm::vec2 position, glm::vec2 directon, RenderComponent* renderRef, HurtboxComponent* hurtboxRef);
	
	void Render() const override {};
	void Update(const float deltatime) override;
	
private:
	RenderComponent* nm_pRenderComp;
	HurtboxComponent* nm_pHurtboxComp;
	
	dae::Transform m_transform;
	glm::vec2 m_Velocity;
	
	
};

