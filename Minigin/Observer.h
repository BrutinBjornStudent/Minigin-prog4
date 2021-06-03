#pragma once

#include "Event.h"
#include "GameObject.h"
#include "healthComponent.h"
#include "ScoreComponent.h"


class Observer
{

public:
	
	~Observer() {};

	//TODO moet iets vinden om een component of object mee te geven
	//want het staat me niet aan dat event zo vaag is.
	virtual void onNotify(const Event event) const = 0;
};

class QbertObserver: public Observer
{
public:

	QbertObserver(HealthComponent* health);
	
	void onNotify(const Event event) const override
	{
		switch (event)
		{
		case Event::player_Died:
			PlayerDied();
			if(nm_pHealth)
				nm_pHealth->loseHealth(1);
			break;
		default:
			std::cout << "qbert observer does default" << std::endl;
		}	
	}

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
	ScoreObserver(ScoreComponent* scoreComp);

	void onNotify( const Event event) const override
	{
		switch (event)
		{
		case Event::tile_color_change:
			nm_pScore->AddScore(25);
			break;
		case Event::defeat_coily:
			nm_pScore->AddScore(500);
			break;
		case Event::disc_remains:
			nm_pScore->AddScore(50);
			break;
		case Event::catching_slick_or_slam:
			nm_pScore->AddScore(300);
			break;
		default:
			std::cout << "something went wrong with score event" << std::endl;
			break;
		}
	}
private:
	ScoreComponent* nm_pScore;
};