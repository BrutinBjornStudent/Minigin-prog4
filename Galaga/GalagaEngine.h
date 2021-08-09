#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <Minigin.h>
class GalagaEngine :
    public dae::Minigin
{
public:
	void LoadGame() override;
	void Update() override;
private:
	std::shared_ptr<dae::GameObject> playerCharacter;
};

