#include "GalagaObservers.h"

#include "EnemyComponent.h"
#include "PlayerComponent.h"
#include "EnemyManagerComp.h"
#include "SceneManager.h"

void GalagaEnemyObserver::OnNotify( BaseComponent* event) const

{
	if (dynamic_cast<const EnemyComponent*>(event))
	{
		std::cout << "Observer recieved BeeComp" << std::endl;

		auto beeVal = dynamic_cast<const EnemyComponent*>(event);

		EnemyStates state = beeVal->GetState();
		auto type = beeVal->GetEnemyType();

		if (state == EnemyStates::Dive_Bomb)
		{
			switch (type)
			{
			case EnemyType::butterfly: 
				nm_pScoreComp->AddScore(160);
				break;
			case EnemyType::bee: 
				nm_pScoreComp->AddScore(100);
				break;
			case EnemyType::Boss: 
				nm_pScoreComp->AddScore(400);
				break;
			default: 
				break;
			}
		}
		else
		{
			switch (type)
			{
			case EnemyType::butterfly:
				nm_pScoreComp->AddScore(80);
				break;
			case EnemyType::bee:
				nm_pScoreComp->AddScore(50);
				break;
			case EnemyType::Boss:
				nm_pScoreComp->AddScore(150);
				break;
			default:
				break;
			}
		}
		
	}
	else
	{
		std::cout << "wrong component linked";
	}

}


void GalagaPlayerObserver::OnNotify( BaseComponent* component) const
{
	if (dynamic_cast<const PlayerComponent*>(component))
	{
		nm_pHealthComp->loseHealth(1);
		nm_pManagerComp->IsAttacking(false);
		if (nm_pHealthComp->GetHealth() <= 0)
		{
			std::cout << "game over." << std::endl;
			nm_GameOverScreen->SetActive(true);

		}
	}
	if (dynamic_cast<const EnemyManagerComp*>(component) && nm_pHealthComp->GetHealth() > 0)
	{
		nm_pPlayer->GetComponent<HitBoxComponent>()->ResetHit();
		nm_pPlayer->SetActive(true);
		nm_pPlayer->GetComponent<ActorComponent>()->Translate(float(m_GameSize.x / 3), float(m_GameSize.y) - 40);

		
	}
	
};
