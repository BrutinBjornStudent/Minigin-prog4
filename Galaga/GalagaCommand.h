#pragma once
#include "Command.h"
#include "GunComponent.h"

class ShootCommand final : public Command
{
public:
	ShootCommand(GunComponent* gun) :m_gun(gun) {};
	void Execute() override { m_gun->Fire(); };
private:
	GunComponent* m_gun;
};
