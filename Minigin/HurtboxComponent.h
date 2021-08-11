#pragma once
#include "Component.h"
class HurtboxComponent :
public BaseComponent
{
public:
	void Render() const override;
	void Update(const float deltatime) override;

private:
	
	
};

