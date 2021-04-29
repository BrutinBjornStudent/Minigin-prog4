#pragma once

#include "Event.h"
#include "GameObject.h"



class Observer
{

public:
	
	virtual ~Observer() {};
	virtual void onNotify(const dae::GameObject& object, Event event) = 0;
};

class QbertObserver: public Observer
{
public:
	virtual void onNotify(const dae::GameObject& qbert, Event event)
	{
		qbert;
		switch (event)
		{
		case Event::player_Died:
			PlayerDied();
			break;
		default:
			std::cout << "qbert observer does default" << std::endl;
		}	
	}
	
private:
	virtual void PlayerDied()
	{
		std::cout << "congrats! you beat the game of staying alive X_X " << std::endl;
	}
};