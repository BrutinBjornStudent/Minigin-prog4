#include "MiniginPCH.h"
#include "HitBoxComponent.h"

#include <SDL_rect.h>
#include <SDL_render.h>



#include "Renderer.h"
#include "structs.h"

HitBoxComponent::HitBoxComponent(glm::ivec2 pos, glm::ivec2 size,int CollisionID)
	:m_rect(pos.x, pos.y, size.x, size.y)
	,m_CollisionID(CollisionID)
{
	//m_offset.x = m_rect.size.x / 2;
	//m_offset.y = m_rect.size.y / 2;
	//m_rect.pos -= m_offset;
}

void HitBoxComponent::Render() const
{
	SDL_Rect sdrect;
	sdrect.x = m_rect.pos.x;
	sdrect.y = m_rect.pos.y;
	sdrect.h = m_rect.size.y;
	sdrect.w = m_rect.size.x;
	dae::Renderer::GetInstance().RenderRect(&sdrect,SDL_Color{0,255,0,255});
}

void HitBoxComponent::Update(const float)
{
	if (m_NeedsUpdate)
	{
		auto pos = m_transform.GetPosition();

		pos.x += m_offset.x + 1;
		pos.y += m_offset.y + 1;

		m_rect.pos = glm::ivec2(pos.x, pos.y);
		m_rect.size.x = m_size.x - 2;
		m_rect.size.y = m_size.y - 2;

	}
}

void HitBoxComponent::SetPosition(float x, float y, float z)
{
	m_transform.SetPosition(x, y, z);
	m_NeedsUpdate = true;
}

void HitBoxComponent::SetPosition(glm::vec3 pos)
{
	m_transform.SetPosition(pos);
	m_NeedsUpdate = true;
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

bool HitBoxComponent::IsSquareInThisHitBox(Rect rect,int CollisionID)
{
	if (m_gotHit)
	{
		return false;
	}
	
	if (CollisionID != m_CollisionID)
	{
		m_gotHit = false;
		return false;
	}
	
	glm::ivec2 Cube1TL = m_rect.pos;
	glm::ivec2 Cube1BR = m_rect.pos + m_rect.size;

	glm::ivec2 Cube2TL = rect.pos;
	glm::ivec2 Cube2BR = rect.pos + rect.size;

	if ((Cube1TL.x <= Cube2BR.x && Cube1BR.x >= Cube2TL.x) && (Cube1TL.y <= Cube2BR.y && Cube1BR.y >= Cube2TL.y) )
	{
		m_gotHit = true;
		return true;
	}
	
	m_gotHit = false;
	return false;
	

}
