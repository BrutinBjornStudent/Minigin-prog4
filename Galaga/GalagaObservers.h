#pragma once
#include "BeeComponent.h"
#include "Observer.h"


enum class GalagaEvent
{
	Bee_InFormation_Kill = 0,
	Bee_Diving_Kill = 1,
	Butterfly_InFormation_Kill = 2,
	Butterfly_Diving_Kill = 3,
	Boss_InFormation_Kill = 4,
	Boss_Diving_Kill = 5
};


//Bee: In formation	50
//Bee : Diving	100
//Butterfly : In formation	80
//Butterfly : Diving	160
//Boss Galaga : In formation	150
//Boss Galaga : Diving	400


class GalagaEnemyObserver: public Observer
{
public:
	GalagaEnemyObserver(ScoreComponent* Score): nm_pScoreComp(Score)
	{
	};

	void onNotify(const BaseComponent* event) const override
	{
		if (dynamic_cast<const BeeComponent*>(event))
		{
			std::cout << "Observer recieved BeeComp" << std::endl;

			auto beeVal = dynamic_cast<const BeeComponent*>(event);
			
			BeeStates state = beeVal->GetState();
			if (state == BeeStates::dying)
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

private:
	ScoreComponent* nm_pScoreComp;
};
