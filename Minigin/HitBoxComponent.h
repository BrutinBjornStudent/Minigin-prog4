#pragma once
#include <glm/vec2.hpp>

#include "Component.h"
#include "structs.h"
#include "Transform.h"

class HitBoxComponent :
    public BaseComponent
{
public:
	// creates the hitboxs and centers it.
	HitBoxComponent(glm::ivec2 pos, glm::ivec2 size, int CollisionID = -1);
	
	void Render() const override;
	void Update(const float ) override;

	void SetRect(const Rect newRect) { m_rect = newRect; };


	void SetOffset(int x, int y) { m_offset.x = x; m_offset.y = y; m_NeedsUpdate = true; };
	void SetPosition(float x, float y, float z);
	void SetPosition(glm::vec3 pos);
	void SetSize(glm::ivec2 size) { m_size = size;  m_NeedsUpdate = true;};

	bool IsHit() { return m_gotHit; };
	
	const glm::ivec2 GetCenter() const { return m_rect.pos + m_offset; };
	const Rect& GetRectangle() const { return m_rect; };

	bool IsPointInThisHitbox(glm::ivec2 point);
	bool IsSquareInThisHitBox(Rect rectangle, int CollisionID);

private:
	Rect m_rect;
	glm::ivec2 m_offset;
	glm::ivec2 m_size;
	dae::Transform m_transform;

	int m_CollisionID = -1;
	
	bool m_NeedsUpdate = true;
	bool m_gotHit = false;
};

