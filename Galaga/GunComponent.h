#pragma once
#include "ActorComponent.h"
#include "Component.h"

// just a spawner for the bullets;
class GunComponent :
    public BaseComponent
{
public:
	void Fire();
	void Update(const float deltaTime ) override;
	void Render() const override{};

	void BindToActor(ActorComponent* ToLink) { nm_pActor = ToLink;  };
private:
	ActorComponent* nm_pActor = nullptr;
	float m_ElapsedTime = 0;
	float m_ShotDelay = 0.2f;
	
	
};


