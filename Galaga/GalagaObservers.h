#pragma once

#include "Observer.h"


class EnemyManagerComp;

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

	void OnNotify( BaseComponent* event) const override;
	//};

private:
	ScoreComponent* nm_pScoreComp;
};


class GalagaPlayerObserver: public Observer
{
public:
	GalagaPlayerObserver(
		HealthComponent* health,EnemyManagerComp* manager, std::shared_ptr<dae::GameObject> player,
		glm::vec2 gameSize,std::shared_ptr<dae::GameObject> gameOver):
		nm_pHealthComp(health),
		nm_pManagerComp(manager),
		nm_pPlayer(player),
		nm_GameOverScreen(gameOver),
		m_GameSize(gameSize) {};

	GalagaPlayerObserver() = default;
	
	void OnNotify( BaseComponent* event) const override;

private:
	glm::vec2 m_GameSize;
	HealthComponent* nm_pHealthComp = nullptr;
	EnemyManagerComp* nm_pManagerComp = nullptr;
	std::shared_ptr<dae::GameObject> nm_GameOverScreen = nullptr;
	std::shared_ptr<dae::GameObject> nm_pPlayer = nullptr;
	bool m_GameEnded = false;
};