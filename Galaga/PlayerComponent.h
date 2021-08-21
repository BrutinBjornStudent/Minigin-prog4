#pragma once
#include "Component.h"
#include "GameObject.h"
#include "HitBoxComponent.h"


class PlayerComponent :
    public BaseComponent
{
public:
	PlayerComponent(dae::GameObject& gameRef,HitBoxComponent* hitbox)
		:nm_ParentRef(gameRef)
		,nm_pHitBox(hitbox)
	{};

	void Render() const override{};
	void Update(const float deltatime) override;
	

private:
	dae::GameObject& nm_ParentRef;
	HitBoxComponent* nm_pHitBox = nullptr;
	
	
	
};

