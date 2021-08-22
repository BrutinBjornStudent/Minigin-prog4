#pragma once
#include "Component.h"
#include "GameObject.h"
#include "HitBoxComponent.h"
#include "Subject.h"




class PlayerComponent :
    public BaseComponent
{
public:
	PlayerComponent(std::shared_ptr<dae::GameObject> gameRef, HitBoxComponent* hitbox)
		:m_PlayerSubject(new Subject)
		,nm_ParentRef(gameRef)
		,nm_pHitBox(hitbox)
	{};
	~PlayerComponent() { delete m_PlayerSubject; }

	void Render() const override{};
	void Update(const float deltatime) override;

	Subject* GetSubject() const { return m_PlayerSubject; }

private:
	std::weak_ptr<dae::GameObject> nm_ParentRef;
	HitBoxComponent* nm_pHitBox = nullptr;
	Subject* m_PlayerSubject = nullptr;
	
	
};

