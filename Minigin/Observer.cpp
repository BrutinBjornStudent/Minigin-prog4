#include "MiniginPCH.h"
#include "Observer.h"

QbertObserver::QbertObserver(HealthComponent* health)
	:nm_pHealth(health)
{
	
}

ScoreObserver::ScoreObserver(ScoreComponent* scoreComp)
	:nm_pScore(scoreComp)
{
}
