#pragma once
#include "Component.h"

class HealthComponent :
    public BaseComponent
{
public:
	HealthComponent(int health);

	void Update(const float) override {};
	void Render() const override {};

	int GetHealth() const noexcept;
	void loseHealth(int damage);
	void setHealth(int newHealth);
private:
	int m_health;

};

