#include "BulletComponent.h"


#include "GameObject.h"
#include "glm/geometric.hpp"


#include "HurtboxComponent.h"


BulletComponent::BulletComponent(glm::vec2 position, glm::vec2 directon, RenderComponent* renderRef,
                                 HurtboxComponent* hurtboxRef,dae::GameObject& gameRef)
	: m_Velocity(directon)
	,nm_pRenderComp(renderRef)
	,nm_pHurtboxComp(hurtboxRef)
	,nm_ParentRef(gameRef)
{
	m_transform.SetPosition(position.x, position.y, 0);
}

void BulletComponent::Update(const float deltatime)
{
	//add veloctiy;
	glm::vec3 newpos = m_transform.GetPosition();

	if (glm::length(m_Velocity) > 0)
	{
		newpos.x += m_Velocity.x * deltatime;
		newpos.y += m_Velocity.y * deltatime;
		
	}

	m_transform.SetPosition(newpos);

	if (nm_pHurtboxComp)
	{
		nm_pHurtboxComp->SetPosition(m_transform.GetPosition());
		if(nm_pHurtboxComp->IsAHit())
		{
			nm_ParentRef.MarkForDeletion();
		}
	}
	if (nm_pRenderComp)
	{
		nm_pRenderComp->SetPosition(m_transform.GetPosition());
	}
	
}

