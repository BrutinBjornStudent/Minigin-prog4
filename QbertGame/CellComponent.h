#pragma once
#include <Component.h>
#include <SDL_pixels.h>
#include <string>
#include <glm/detail/type_vec2.hpp>


#include "Transform.h"
#include "RenderComponent.h"

class CellComponent :
    public BaseComponent
{
public:
	
	CellComponent(const glm::vec3& pos, const glm::ivec2& boardPos, RenderComponent* render, float rad);

	void Update(const float ) override {};
	void Render() const override;

	glm::vec2 getSpritePos();

private:
	float m_radius;
	glm::ivec2 m_coordinate;

	dae::Transform m_Transform;

	RenderComponent* nm_pRenderComponent = nullptr;


	
};


