#pragma once

#include "Renderer.h"
#include "Transform.h"
#include "Texture2D.h"
#include "glm/vec2.hpp"
#include "string"
#include "SDL_rect.h"

class RenderComponent : public BaseComponent
{
public:
	RenderComponent() = default;
	virtual ~RenderComponent()
	{
		delete m_pTexture;
		delete m_pSrcRect;
	};

	void Update(const float) override {};
	
	void Render() const override
	{
		if (m_pTexture)
		{
			const glm::vec3& pos = m_transform.GetPosition() + glm ::vec3(m_offset,0);

			if (!m_IsSizeSet)
				dae::Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y,m_Rotation);			
			else if (!m_pSrcRect)
				dae::Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y, m_Size.x, m_Size.y,m_Rotation);
			else
				dae::Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y, m_Size.x, m_Size.y,*m_pSrcRect,m_Rotation);
		}
	};
	
	void SetPosition(float x, float y, float z = 0);
	void SetPosition(glm::vec3 pos);
	void SetSize(int x, int y);
	void SetOffset(int x, int y);
	void SetRotation(double rot) { m_Rotation = rot; };
	void SetTexture(const std::string& filename);
	void SetTexture(dae::Texture2D* texture2D);
	void SetSourceRect(SDL_Rect rect);

protected:
	dae::Texture2D* m_pTexture = nullptr;
	SDL_Rect* m_pSrcRect = nullptr;
	dae::Transform m_transform;

	bool m_IsSizeSet;
	bool m_IsBoundToOtherComp = false;
	glm::ivec2 m_Size{0,0};
	glm::vec2 m_offset{ 0,0 };
	double m_Rotation = 0.0;

};

