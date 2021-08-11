#pragma once
#include "Component.h"
#include "AllComponents.h"
class BeeComponent :
    public BaseComponent
{

public:
	void Render() const override{};
	void Update(const float deltatime) override ;

	void LinkSpriteComp(SpriteComponent* SpriteManager) { nm_SpriteManager = SpriteManager; }

private:

	SpriteComponent* nm_SpriteManager = nullptr;
	
	float m_NextSpriteTreshhold = 0.5f;
	float m_SpriteElapsedTime = 0.0f;
	

	
};

