#pragma once
#include "ActorComponent.h"
#include "Component.h"
#include "AllComponents.h"


enum class BeeStates
{
	Spawning = 0,
	dying = 10
};

class BeeComponent :
    public BaseComponent
{

public:
	BeeComponent(dae::GameObject& gameRef) :nm_ParentRef(gameRef),m_BeeSubject(new Subject){};
	~BeeComponent() override { delete m_BeeSubject; };
	
	
	Subject* GetSubject() const { return m_BeeSubject; }
	
	void Render() const override{};
	void Update(const float deltatime) override ;
	BeeStates GetState() const { return  m_BeeState; };
	void LinkSpriteComp(SpriteComponent* SpriteManager) { nm_SpriteManager = SpriteManager; }
	void LinkActorComp(ActorComponent* actorToLink) { nm_ActorComp = actorToLink; }
	void BindHitBoxComponent(HitBoxComponent* HitBoxToLink) { nm_pHitbox = HitBoxToLink; };
private:
	dae::GameObject& nm_ParentRef;
	SpriteComponent* nm_SpriteManager = nullptr;
	ActorComponent* nm_ActorComp = nullptr;
	HitBoxComponent* nm_pHitbox = nullptr;
	
	Subject* m_BeeSubject = nullptr;
	BeeStates  m_BeeState = BeeStates::Spawning;
	
	float m_NextSpriteTreshhold = 0.5f;
	float m_SpriteElapsedTime = 0.0f;
	

	
};

