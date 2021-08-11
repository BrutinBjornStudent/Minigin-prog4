#pragma once
#include <glm/vec2.hpp>

#include "Component.h"
#include "structs.h"

class HitBoxComponent :
    public BaseComponent
{
public:
	// creates the hitboxs and centers it.
	HitBoxComponent(Rect hitbox);
	
	void Render() const override{};
	void Update(const float ) override{};

	const glm::ivec2 GetCenter() const { return m_rect.pos + m_offset; };
	const Rect& GetRectangle() const { return m_rect; };

	bool IsPointInThisHitbox(glm::ivec2 point);
	bool IsSquareInThisHitBox(Rect rectangle);

private:
	Rect m_rect;
	glm::ivec2 m_offset;
};

