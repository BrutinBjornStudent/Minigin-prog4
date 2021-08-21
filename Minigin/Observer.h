#pragma once

#include "GameObject.h"
#include "healthComponent.h"
#include "ScoreComponent.h"


class Observer
{
public:
	virtual void OnNotify(const BaseComponent* event) const = 0;
};

class QbertObserver: public Observer
{
public:

	QbertObserver(HealthComponent* health):nm_pHealth(health) {};
	void OnNotify(const BaseComponent*)const override {} ;


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

	void OnNotify( const BaseComponent* ) const override
	{
		//switch (event)
		//{
		//case Event::tile_color_change:
		//	nm_pScore->AddScore(25);
		//	break;
		//case Event::defeat_coily:
		//	nm_pScore->AddScore(500);
		//	break;
		//case Event::disc_remains:
		//	nm_pScore->AddScore(50);
		//	break;
		//case Event::catching_slick_or_slam:
		//	nm_pScore->AddScore(300);
		//	break;
		//default:
		//	std::cout << "something went wrong with score event" << std::endl;
		//	break;
		//}
	}
private:
	ScoreComponent* nm_pScore;
};