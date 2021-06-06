#pragma once
#include "Component.h"
#include "Subject.h"



class ActorComponent :
    public BaseComponent
{

public:
	ActorComponent();
	~ActorComponent();
	
	Subject* GetSubject() const { return m_actorChanged; };

	void Update( float delta) override;
	void Render() const override {};

	void Jump() const;
	void Die() const;
	void Fire() const;
	void Duck() const;
	void Fart() const;
	virtual void MoveTo(float x, float y);
	glm::vec3 GetPosition() { return m_transform.GetPosition(); };

private:
	Subject* m_actorChanged = nullptr;

	dae::Transform m_transform;
	glm::vec3 m_velocity;
	
	
};

