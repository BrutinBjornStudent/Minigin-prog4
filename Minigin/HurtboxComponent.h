#pragma once
#include "Component.h"
#include "HitBoxComponent.h"
#include "structs.h"
#include "Transform.h"



class HurtboxComponent :
public BaseComponent
{
public:
	HurtboxComponent(glm::ivec2 pos, glm::ivec2 size);
	
	void Render() const override;
	void Update(const float deltatime) override;
	void SetRect(const Rect newRect) { m_rect = newRect; };

	
	void SetOffset(int x, int y);
	void SetPosition(float x, float y, float z);
	void SetPosition(glm::vec3 pos);
	void SetSize(glm::ivec2 size);
	bool IsOverlappingHitbox(HitBoxComponent* hitbox);


private:
	Rect m_rect;
	glm::ivec2 m_offset;
	glm::ivec2 m_size;
	dae::Transform m_transform;

	bool m_NeedsUpdate;
};

inline void HurtboxComponent::SetSize(glm::ivec2 size)
{
	m_size.x = size.x;
	m_size.y = size.y;
	m_NeedsUpdate = true;
}

