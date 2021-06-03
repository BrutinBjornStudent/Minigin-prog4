#pragma once
#include "GameObject.h"
#include "Subject.h"

class QBert final
{

public:
	QBert();
	~QBert();
	//void SetSubject(Subject* newSubject);

	Subject* GetSubject() const;
	
	void Jump();
	void Die();
	void Fire();
	void Duck();
	void Fart();
private:
	Subject* m_ActorChanged = nullptr;
};

