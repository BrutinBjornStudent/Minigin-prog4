#pragma once
#include "Component.h"
#include "Subject.h"
class QBertComponent :
    public BaseComponent
{

public:
	QBertComponent();
	~QBertComponent();
	
	Subject* GetSubject() const { return m_actorChanged; };

	void Update( float) override {};
	void Render() const override {};

	void Jump() const;
	void Die() const;
	void Fire() const;
	void Duck() const;
	void Fart() const;
private:
	Subject* m_actorChanged = nullptr;
	
};

