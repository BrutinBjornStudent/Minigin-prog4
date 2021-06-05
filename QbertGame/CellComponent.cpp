#include "CellComponent.h"

#include <SDL.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>

//https://www.redblobgames.com/grids/hexagons/



CellComponent::CellComponent(const glm::vec3& pos, const glm::ivec2& boardPos, RenderComponent* rendercomp, float rad)
	:m_radius(rad)
	, m_coordinate(boardPos)
	, nm_pRenderComponent(rendercomp)

{
	m_Transform.SetPosition(pos);

}



void CellComponent::Render() const
{
}

glm::vec2 CellComponent::getSpritePos()
{
	glm::vec2 spritepos;
	spritepos = m_Transform.GetPosition();

	spritepos.y -= m_radius / 2;
	return spritepos;
}
