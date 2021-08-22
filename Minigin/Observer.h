#pragma once

#include "GameObject.h"
#include "healthComponent.h"
#include "ScoreComponent.h"


class Observer
{
public:
	virtual void OnNotify( BaseComponent* event) const = 0;
};

class QbertObserver: public Observer
{
public:

	QbertObserver(HealthComponent* health):nm_pHealth(health) {};
	void OnNotify( BaseComponent*)const override {} ;


private:
	void PlayerDied() const
	{
		std::cout << "congrats! you beat the game of staying alive X_X " << std::endl;
	}
	HealthComponent* nm_pHealth;
};


class ScoreObserver : public Observer
{
public:
	ScoreObserver(ScoreComponent* scoreComp):nm_pScore(scoreComp){};

	void OnNotify(  BaseComponent* ) const override
	{

	}
private:
	ScoreComponent* nm_pScore;
};