#include "MiniginPCH.h"
#include "HitBoxComponent.h"

#include "structs.h"

HitBoxComponent::HitBoxComponent(Rect hitbox)
	:m_rect(hitbox.pos.x,hitbox.pos.y,hitbox.size.x,hitbox.size.y)
{
	m_offset.x = m_rect.size.x / 2;
	m_offset.y = m_rect.size.y / 2;
	m_rect.pos -= m_offset;
}

bool HitBoxComponent::IsPointInThisHitbox(glm::ivec2 point)
{
	glm::ivec2 topLeft = m_rect.pos;
	glm::ivec2 BottomRight = m_rect.pos + m_rect.size;


	if (topLeft.x <= point.x && topLeft.y <= point.y )
	{
		if (BottomRight.x >= point.x && BottomRight.y >= point.y)
		{
			return true;
		}
		return false;
	}
	return false;
	
	
}

bool HitBoxComponent::IsSquareInThisHitBox(Rect )
{
	return false;
}
