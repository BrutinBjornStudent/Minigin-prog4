#pragma once
#include "ActorComponent.h"
#include "Component.h"
#include "AllComponents.h"
#include "EnemySpawner.h"


class BezierMoveComponent;

enum class BeeStates
{
	Spawning = 0,
	Move_Into_Field = 1,
	Move_to_ArraySpot = 2,
	Stay_On_Spot = 3,
	dying = 10
};


// manages the score,stages, selfdestruct, and should manage the Actor itself
class BeeComponent :
    public BaseComponent
{

public:
	BeeComponent(dae::GameObject& gameRef)
	:nm_ParentRef(gameRef),
	m_BeeSubject(new Subject)
	{};
	~BeeComponent() override { delete m_BeeSubject; }
	Subject* GetSubject() const { return m_BeeSubject; }
	
	void Render() const override{};
	void Update(const float deltatime) override ;
	BeeStates GetState() const { return  m_BeeState; };
	
	void BindSpriteComp(SpriteComponent* SpriteManager) { nm_SpriteManager = SpriteManager; }
	void BindActorComp(ActorComponent* actorToLink) { nm_ActorComp = actorToLink; }
	void BindHitBoxComponent(HitBoxComponent* HitBoxToLink) { nm_pHitbox = HitBoxToLink; };
	void BindEnemySpawnerComp(EnemySpawner* SpawnerToLink) { nm_pEnemySpawner = SpawnerToLink; }
	void BindSpriteComp(RenderComponent* RenderToLink) { nm_pRenderComp = RenderToLink; };
	void SetState(BeeStates state) { m_BeeState = state; }
	void SetScreenPosition(GridPos gridPos) { m_FieldPosition = gridPos; };
	void SetBazierID(int BazierID) { m_BazierID = BazierID; };


private:

	glm::vec2 CheckAndSetNextBazierPoint();
	dae::GameObject& nm_ParentRef;
	SpriteComponent* nm_SpriteManager = nullptr; // sprite
	RenderComponent* nm_pRenderComp = nullptr;
	ActorComponent* nm_ActorComp = nullptr; // for moveCommands
	HitBoxComponent* nm_pHitbox = nullptr; // hitbox

	EnemySpawner* nm_pEnemySpawner = nullptr;
	int m_CurrentBazierPoint = 0;
	int m_BazierID = 0;
	
	
	Subject* m_BeeSubject = nullptr;

	//TODO: might not fit here;
	std::vector<glm::vec2> m_PointsToFollow; // points to follow
	GridPos m_FieldPosition; // grid position
	
	
	BeeStates  m_BeeState = BeeStates::Spawning; // state
	
	float m_NextSpriteTreshhold = 0.5f;
	float m_SpriteElapsedTime = 0.0f;
};

