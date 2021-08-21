#include "PlayerComponent.h"

#include "EnemyComponent.h"

void PlayerComponent::Update(const float )
{
	if (nm_pHitBox)
	{
		if (nm_pHitBox->IsHit())
		{
			nm_ParentRef.MarkForDeletion();
		}
	}
	
}
