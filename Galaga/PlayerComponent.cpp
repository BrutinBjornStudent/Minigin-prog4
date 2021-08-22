#include "PlayerComponent.h"

#include "EnemyComponent.h"

void PlayerComponent::Update(const float )
{
	if (nm_pHitBox)
	{
		if (nm_pHitBox->IsHit())
		{

			m_PlayerSubject->Notify(this);
			auto a = nm_ParentRef.lock();
			a->GetComponent<ActorComponent>()->Translate(-200, -200);
			a->SetActive(false);
		}
	}
	
}
