#include "BeeComponent.h"

#include <iostream>
#include <glm/detail/func_geometric.inl>


#include "BezierMoveComponent.h"


void BeeComponent::Update(const float deltatime)
{
	if (nm_SpriteManager)
	{		
		m_SpriteElapsedTime += deltatime;
		if (m_SpriteElapsedTime >= m_NextSpriteTreshhold)
		{
			m_SpriteElapsedTime -= m_NextSpriteTreshhold;
			std::cout << "next sprite triggered" << std::endl;
			nm_SpriteManager->NextSpriteX();
		}
	}
	if (nm_pHitbox)
	{
		
		if (nm_pHitbox->IsHit())
		{
			m_BeeState = BeeStates::dying;
			nm_ParentRef.MarkForDeletion();
		}	
	}

	glm::vec2 target;
	glm::vec2 dir;
	
	switch (m_BeeState)
	{
	case BeeStates::Spawning:

		// if spawning move onto screen
		//nm_pBazierMove->SetRun(true);
		//auto target = nm_pBazierMove->GetPoint(); // get current pos on the brazier
		nm_ActorComp->MoveTo(0,1.f); // set Actor There,
		
		if (nm_ActorComp->GetPosition().y >= 30)
		{
			m_BeeState = BeeStates::Move_to_ArraySpot;
		}
		break;
		
	case BeeStates::Move_Into_Field:
		break;
		
	case BeeStates::Move_to_ArraySpot :

		target = m_FieldPosition.screenPos - glm::vec2(nm_ActorComp->GetPosition().x, nm_ActorComp->GetPosition().y);

		dir = glm::normalize(target);
		nm_ActorComp->MoveTo(dir.x,dir.y);

		nm_pRenderComp->SetRotation(atan2(dir.y, dir.x) * (180 / M_PI) + 90);
		if (glm::length(target) < 0.5f)
		{
			m_BeeState = BeeStates::Stay_On_Spot;
		}
		break;

	case BeeStates::Stay_On_Spot:

		nm_pRenderComp->SetRotation(0);

		break;
		
	case BeeStates::dying:

		m_BeeSubject->Notify(this);
		break;
		
	default: ;
	}
	
	

	
}
