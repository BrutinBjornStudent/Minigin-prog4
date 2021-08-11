#pragma once
#include "Component.h"
#include "Subject.h"


class ActorHitBoxComponent;

class ActorComponent :
    public BaseComponent
{
public:
	ActorComponent();
	~ActorComponent();
	
	Subject* GetSubject() const { return m_actorChanged; };

	void Update( float delta) override;
	void Render() const override {};


	//ations
	void Jump() const;
	void Die() const;
	void Fire() const;
	void Duck() const;
	void Fart() const;
	
	void MoveTo(float x, float y);
	void Translate(float x, float y);
	
	void BindRenderComponent(RenderComponent* toBind) { nm_pBoundRenderComp = toBind; };
	
	glm::vec3 GetPosition() const { return m_transform.GetPosition(); };

private:
	Subject* m_actorChanged = nullptr;
	RenderComponent* nm_pBoundRenderComp = nullptr;

	dae::Transform m_transform;
	glm::vec2 m_velocity;

	float m_speed = 100.f;
	
	
};



