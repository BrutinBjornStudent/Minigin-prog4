#include "GalagaObservers.h"

#include "EnemyComponent.h"

void GalagaEnemyObserver::OnNotify(const BaseComponent* event) const

{
	if (dynamic_cast<const EnemyComponent*>(event))
	{
		std::cout << "Observer recieved BeeComp" << std::endl;

		auto beeVal = dynamic_cast<const EnemyComponent*>(event);

		EnemyStates state = beeVal->GetState();
		if (state == EnemyStates::dying)
		{

			nm_pScoreComp->AddScore(50);
			std::cout << "recieved beeComp witchs is dying" << std::endl;

		}

	}
	else
	{
		std::cout << "wrong component linked";
	}

};
