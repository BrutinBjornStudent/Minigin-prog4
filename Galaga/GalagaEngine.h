#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <Minigin.h>
#include "GalagaObservers.h"



class GalagaEngine :
    public dae::Minigin
{
public:
	void LoadGame() override;

private:

	
	void LoadInputs() const;

	
	std::shared_ptr<dae::GameObject> playerCharacter;
	GalagaEnemyObserver m_EnemyObserver = 0;
	glm::vec2 m_size;
	
};

