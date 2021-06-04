#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <Minigin.h>
class QbertEngine :
    public dae::Minigin
{
public:
	void LoadGame() override;
	
};

