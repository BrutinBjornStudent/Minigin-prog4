#include "MiniginPCH.h"
#include "HurtboxComponent.h"

#include <SDL_rect.h>



#include "HitBoxManager.h"
#include "Renderer.h"


HurtboxComponent::HurtboxComponent(glm::ivec2 pos, glm::ivec2 size,int CollisionID)
	:m_rect(pos.x,pos.y,size.x,size.y)
	,m_size(size)
	,m_ColisionID(CollisionID)
{
	
}

void HurtboxComponent::Render() const
{
	SDL_Rect sdrect;
	sdrect.x = m_rect.pos.x;
	sdrect.y = m_rect.pos.y;
	sdrect.h = m_rect.size.y;
	sdrect.w = m_rect.size.x;
	dae::Renderer::GetInstance().RenderRect(&sdrect);
}

void HurtboxComponent::Update(const float )
{
	if (m_NeedsUpdate)
	{
		auto pos = m_transform.GetPosition();

		pos.x += m_offset.x + 1;
		pos.y += m_offset.y + 1;
		
		m_rect.pos = glm::ivec2( pos.x ,pos.y );
		m_rect.size.x = m_size.x - 2;
		m_rect.size.y = m_size.y - 2;

	}
	
	m_hasHit = false;

	auto &vectorRef = dae::HitBoxManager::GetInstance().GetAllHitBoxes();
	for (int i = 0; i < vectorRef.size(); i++)
	{
		if (vectorRef[i]->IsSquareInThisHitBox(m_rect,m_ColisionID))
		{
			//std::cout << "hurtbox is overlapping hitbox" << std::endl;
			m_hasHit = true;


		}
	}
	

}

void HurtboxComponent::SetOffset(int x, int y)
{
	m_offset.x = x;
	m_offset.y = y;
	m_NeedsUpdate = true; 
}

void HurtboxComponent::SetPosition(float x, float y, float z)
{
	m_transform.SetPosition(x, y, z); 
}

void HurtboxComponent::SetSize(glm::ivec2 size)
{
	m_size.x = size.x;
	m_size.y = size.y;
	m_NeedsUpdate = true;
}

void HurtboxComponent::SetPosition(glm::vec3 pos)
{
	SetPosition(pos.x, pos.y, pos.z);
	m_NeedsUpdate = true; 
}

bool HurtboxComponent::IsOverlappingHitbox(HitBoxComponent* hitbox)
{

	bool hit = hitbox->IsSquareInThisHitBox(m_rect,m_ColisionID);
	if (hit)
		m_hasHit = true;
	return hit;
}
