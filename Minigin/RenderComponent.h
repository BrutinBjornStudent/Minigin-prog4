#pragma once

#include "Renderer.h"
#include "Transform.h"
#include "Texture2D.h"
#include "glm/vec2.hpp"
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
			const glm::vec3& pos = m_transform.GetPosition()+ glm ::vec3(m_offset,0);


			if (!m_pSrcRect)
				dae::Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y, m_Size.x, m_Size.y);
			else
				dae::Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y, m_Size.x, m_Size.y,*m_pSrcRect);
		}
	};
	
	//virtual void Update(const float) {};
	void SetPosition(float x, float y);
	void SetSize(float x, float y);
	void SetOffset(int x, int y);
	void SetTexture(const std::string& filename);
	void SetTexture(dae::Texture2D* texture2D);
	void SetSourceRect(SDL_Rect rect);

protected:
	dae::Texture2D* m_pTexture = nullptr;
	SDL_Rect* m_pSrcRect = nullptr;
	dae::Transform m_transform;
	glm::vec2 m_Size{1,1};
	glm::vec2 m_offset{ 0,0 };

};

