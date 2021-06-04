#pragma once
#include <Component.h>
#include <SDL_pixels.h>
#include <glm/detail/type_vec2.hpp>


#include "Transform.h"

class CellComponent :
    public BaseComponent
{
public:
	
	CellComponent(const glm::vec3& pos, const glm::ivec3& boardPos, const SDL_Color& color, float rad);

	void Update(const float ) override {};
	void Render() const override;


private:
	float m_radius;
	glm::ivec3 m_coordinate;

	glm::vec2 m_top;
	glm::vec2 m_topRight;
	glm::vec2 m_topLeft;
	glm::vec2 m_bottomleft;
	glm::vec2 m_bottomright;
	glm::vec2 m_bottom;

	
	dae::Transform m_Transform;
	SDL_Color m_color;
	SDL_Color m_colorBottomRight;
	SDL_Color m_colorBottomLeft;
};


