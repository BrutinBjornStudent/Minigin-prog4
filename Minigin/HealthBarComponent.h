#pragma once


#include "Component.h"
#include "healthComponent.h"
#include "Renderer.h"
#include "Texture2D.h"
#include "Transform.h"
#include "glm/vec2.hpp"


enum class Direction
{
	horizontal = 0,
	vertical = 1
};

class HealthBarComponent : public BaseComponent
{
public:
	HealthBarComponent(HealthComponent* healthref);
	virtual ~HealthBarComponent()
	{
		delete m_pTexture;
	};

	void Update(const float) override {};
	void Render() const override
	{
		if (m_pTexture)
		{
			int current = nm_pHealthComp->GetHealth();

			if (m_direction == Direction::horizontal)
			{
				for (int index = 0; index < current; index++)
				{
					const glm::vec3& pos = m_transform.GetPosition();
					dae::Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x + index * m_Size.x, pos.y,
						m_Size.x,m_Size.y);
				}				
			}
			else
			{
				for (int index = 0; index <= current; index++)
				{
					const glm::vec3& pos = m_transform.GetPosition();
					dae::Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y + index * m_Size.y,
						m_Size.x,m_Size.y);
				}
			}
		}
	};

	//virtual void Update(const float) {};
	void SetPosition(float x, float y);
	void SetDirection(Direction direction);
	void SetSize(glm::vec2 size);
	void SetTexture(const std::string& filename);
	void SetTexture(dae::Texture2D* texture2D);

protected:
	dae::Texture2D* m_pTexture = nullptr;
	dae::Transform m_transform;
	glm::ivec2 m_Size;

	HealthComponent* nm_pHealthComp;
	Direction m_direction = Direction::horizontal;



	
};
