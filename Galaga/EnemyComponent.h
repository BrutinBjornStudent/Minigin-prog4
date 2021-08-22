#pragma once
#include "ActorComponent.h"
#include "Component.h"
#include "AllComponents.h"
#include "EnemyManagerComp.h"


class BezierMoveComponent;

enum class EnemyStates
{
	Spawning = 0,
	Move_Into_Field = 1,
	Move_to_ArraySpot = 2,
	Stay_On_Spot = 3,
	Dive_Bomb = 4,
	Diving = 5,
	dying = 10
};

enum class EnemyType
{
	butterfly = 0,
	bee = 1,
	Boss = 2
};


// manages the score,stages, selfdestruct, and should manage the Actor itself
class EnemyComponent :
    public BaseComponent
{

public:
	EnemyComponent(dae::GameObject& gameRef,EnemyType type)
	:nm_ParentRef(gameRef),
	m_BeeSubject(new Subject),
	m_EnemyType(type)
	{
		if (type == EnemyType::Boss)
		{
			m_lives = 2;
		}
		
	};
	
	~EnemyComponent() override { delete m_BeeSubject; }
	Subject* GetSubject() const { return m_BeeSubject; }
	
	void Render() const override{};
	void Update(const float deltatime) override ;

	EnemyStates GetState() const { return  m_BeeState; };
	EnemyType GetEnemyType() const { return m_EnemyType; }
	
	void BindSpriteComp(SpriteComponent* SpriteManager) { nm_SpriteManager = SpriteManager; }
	void BindActorComp(ActorComponent* actorToLink) { nm_ActorComp = actorToLink; }
	void BindHitBoxComponent(HitBoxComponent* HitBoxToLink) { nm_pHitbox = HitBoxToLink; }
	void BindEnemySpawnerComp(EnemyManagerComp* SpawnerToLink) { nm_pEnemySpawner = SpawnerToLink; }
	void BindSpriteComp(RenderComponent* RenderToLink) { nm_pRenderComp = RenderToLink; }
	void SetState(EnemyStates state) { m_BeeState = state; }
	void SetBazierPattern(std::vector<glm::vec2> BazierPattern) { m_BazierPattern = BazierPattern; };
	void SetGameSize(glm::vec2 size) { m_GameSize = size; }
	void SetScreenPosition(GridPos gridPos) { m_FieldPosition = gridPos; };
	void SetBazierID(int BazierID) { m_BazierID = BazierID; };


private:
	glm::vec2 CheckAndSetNextBazierPoint();
	
	dae::GameObject& nm_ParentRef;
	SpriteComponent* nm_SpriteManager = nullptr; // sprite
	RenderComponent* nm_pRenderComp = nullptr;
	ActorComponent* nm_ActorComp = nullptr; // for moveCommands
	HitBoxComponent* nm_pHitbox = nullptr; // hitbox
	
	glm::vec2 m_BombDirection = glm::vec2(0.f, 1.f);
	std::vector<glm::vec2> m_BazierPattern;
	
	
	EnemyManagerComp* nm_pEnemySpawner = nullptr;
	int m_CurrentBazierPoint = 0;
	int m_BazierID = 0;
	float m_NextBazierRange = 2.f;

	int m_lives = 1;
	
	Subject* m_BeeSubject = nullptr;
	GridPos m_FieldPosition; // grid position
	glm::vec2 m_GameSize = glm::vec2();
	
	EnemyStates m_BeeState = EnemyStates::Spawning; // state
	EnemyType m_EnemyType;
	
	float m_NextSpriteTreshhold = 5.f;
	float m_SpriteElapsedTime = 0.0f;
};

