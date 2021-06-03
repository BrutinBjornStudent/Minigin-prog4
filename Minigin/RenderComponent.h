#pragma once

#include "Renderer.h"
#include "Transform.h"
#include "Texture2D.h"
#include "glm/vec2.hpp"

class RenderComponent : public BaseComponent
{
public:
	RenderComponent() = default;
	virtual ~RenderComponent()
	{
		delete m_pTexture;
	};

	void Update(const float) override {};
	
	void Render() const override
	{
		if (m_pTexture)
		{
			const glm::vec3& pos = m_transform.GetPosition();
			dae::Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x,pos.y);			
		}
	};
	
	//virtual void Update(const float) {};
	void SetPosition(float x, float y);
	void SetTexture(const std::string& filename);
	void SetTexture(dae::Texture2D* texture2D);

protected:
	dae::Texture2D* m_pTexture = nullptr;
	dae::Transform m_transform;
	glm::vec2 m_Size;

};

