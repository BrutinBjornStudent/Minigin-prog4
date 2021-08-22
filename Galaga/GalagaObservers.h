#pragma once

#include "Observer.h"


class PlayerComponent;

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
	GalagaEnemyObserver(ScoreComponent* Score):
	nm_pScoreComp(Score) {};

	void OnNotify(const BaseComponent* event) const override;
	//};

private:
	ScoreComponent* nm_pScoreComp;
};

class GalagaPlayerObserver: public  Observer
{
public:
	GalagaPlayerObserver(HealthComponent* health)
		:nm_pHealthComp(health)
	{};

	void OnNotify(const BaseComponent* event) const override;

private:
	HealthComponent* nm_pHealthComp;
	
};