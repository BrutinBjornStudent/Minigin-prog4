#include "MiniginPCH.h"
#include "healthComponent.h"

HealthComponent::HealthComponent(int health)
	:m_health(health)
{
	
}

int HealthComponent::GetHealth() const noexcept
{
	return m_health;
}

void HealthComponent::loseHealth(int damage) 
{
	m_health -= damage;
	std::cout << "health lost" << std::endl;
}

void HealthComponent::setHealth(int newHealth)
{
	m_health = newHealth;
}
