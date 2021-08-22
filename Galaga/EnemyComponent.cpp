#include "EnemyComponent.h"

#include <iostream>
#include <glm/detail/func_geometric.inl>

#include "math.h"
#include "BezierMoveComponent.h"


void EnemyComponent::Update(const float deltatime)
{
	if (nm_SpriteManager) // updates sprite
	{		
		m_SpriteElapsedTime += deltatime;
		if (m_SpriteElapsedTime >= m_NextSpriteTreshhold)
		{
			m_SpriteElapsedTime -= m_NextSpriteTreshhold;
			std::cout << "next sprite triggered" << std::endl;
			nm_SpriteManager->NextSpriteX();
		}
		//nm_SpriteManager->setYSprite(m_lives);
		
	}
	if (nm_pHitbox)
	{
		
		if (nm_pHitbox->IsHit())
		{
			m_lives--;
			if (m_lives >= 0)
			{
				//m_BeeState = EnemyStates::dying;
				m_BeeSubject->Notify(this);
				nm_ParentRef.MarkForDeletion();				
			}
			else
			{
				nm_pHitbox->ResetHit();
			}
		}	
	}

	glm::vec2 target;
	glm::vec2 dir;

	
	
	switch (m_BeeState)
	{
	case EnemyStates::Spawning:
		m_BazierPattern = nm_pEnemySpawner->GetBazierPaths()[m_BazierID];


		//target = nm_pEnemySpawner->GetBazierPaths()[m_BazierID][0] - 
		//	glm::vec2(nm_ActorComp->GetPosition().x, nm_ActorComp->GetPosition().y);
		//dir = glm::normalize(target);
		//nm_ActorComp->SetVelocity(dir.x, dir.y);

		//nm_pRenderComp->SetRotation(atan2(dir.y, dir.x) * (180 / M_PI) + 90);
		//if (glm::length(target) < m_NextBazierRange)
		//{
		m_CurrentBazierPoint++;
		m_BeeState = EnemyStates::Move_Into_Field;
		//}
		break;

		
	case EnemyStates::Move_Into_Field: // Follow Bazier points


		target = CheckAndSetNextBazierPoint();
		dir = glm::normalize(target);
		nm_ActorComp->SetVelocity(dir.x, dir.y);

		nm_pRenderComp->SetRotation(atan2(dir.y, dir.x) * (180 / M_PI) + 90);
		
		if (m_CurrentBazierPoint == m_BazierPattern.size() - 1)
		{
			m_BeeState = EnemyStates::Move_to_ArraySpot;
		}		
		break;
		
	case EnemyStates::Move_to_ArraySpot :

		target = m_FieldPosition.screenPos - glm::vec2(nm_ActorComp->GetPosition().x, nm_ActorComp->GetPosition().y);
		dir = glm::normalize(target);
		nm_ActorComp->SetVelocity(dir.x,dir.y);

		nm_pRenderComp->SetRotation(atan2(dir.y, dir.x) * (180 / M_PI) + 90);
		if (glm::length(target) < m_NextBazierRange)
		{
			m_BeeState = EnemyStates::Stay_On_Spot;
		}
		break;

	case EnemyStates::Stay_On_Spot:

		nm_ActorComp->SetVelocity(0, 0);
		nm_pRenderComp->SetRotation(0);

		break;

	case EnemyStates::Dive_Bomb:


		m_CurrentBazierPoint = 0;
		m_BazierPattern = nm_pEnemySpawner->CreateAttackPattern(nm_ActorComp->GetPosition());
		m_BeeState = EnemyStates::Diving;
		break;

	case EnemyStates::Diving:

		if (m_CurrentBazierPoint < m_BazierPattern.size() - 1)
		{
			target = CheckAndSetNextBazierPoint();
			dir = glm::normalize(target);
			nm_ActorComp->SetVelocity(dir.x, dir.y);
			nm_pRenderComp->SetRotation(atan2(dir.y, dir.x)* (180 / M_PI) + 90);
		}
		else
		{
			if (m_EnemyType == EnemyType::bee)
				m_BeeState = EnemyStates::Move_to_ArraySpot;
			if(m_EnemyType == EnemyType::butterfly)
			{
				nm_ActorComp->SetVelocity(m_BombDirection.x,m_BombDirection.y);
				nm_pRenderComp->SetRotation(atan2(dir.y, dir.x)* (180 / M_PI) + 90);
			}
		}		
		break;

		
	case EnemyStates::dying:
		break;

	default:
		break;
	}
	
	

	
}

glm::vec2 EnemyComponent::CheckAndSetNextBazierPoint()
{
	glm::vec2 target = m_BazierPattern[m_CurrentBazierPoint] -
		glm::vec2(nm_ActorComp->GetPosition().x, nm_ActorComp->GetPosition().y);

	if (glm::length(target) <= m_NextBazierRange && (m_BazierPattern.size() - 1) > m_CurrentBazierPoint)
	{
		m_CurrentBazierPoint++;
		CheckAndSetNextBazierPoint();
	}

	return target;
	
}
