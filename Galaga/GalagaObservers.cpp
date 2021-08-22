#include "GalagaObservers.h"

#include "EnemyComponent.h"

void GalagaEnemyObserver::OnNotify(const BaseComponent* event) const

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

};
