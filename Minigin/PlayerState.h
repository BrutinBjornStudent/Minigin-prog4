#pragma once
#include "Component.h"
#include "ActorComponent.h"
class PlayerState
{
public:
	
	virtual ~PlayerState() {};
	virtual void HandleInput(ActorComponent& ) {};
	virtual void Update() {};
};



