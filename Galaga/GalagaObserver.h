#pragma once
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

class GalagaObserver :
    public Observer
{
public:
	GalagaObserver(ScoreComponent* scoreComp);

	void onNotify(const Event event) const override
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

