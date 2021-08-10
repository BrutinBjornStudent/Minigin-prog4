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
	void LinkRenderComp(RenderComponent* RendererComp) { nm_pRenderer = RendererComp; }

private:
	
	RenderComponent* nm_pRenderer;
	SpriteComponent* nm_SpriteManager;
	
	float m_NextSpriteTreshhold = 1.f;
	float m_SpriteElapsedTime;

	
};

