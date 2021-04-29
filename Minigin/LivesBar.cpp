#include "MiniginPCH.h"
#include "LivesBar.h"

#include "Renderer.h"

LivesBar::LivesBar(int lives)
	:m_Lives(lives)
{
}



void LivesBar::Render() const
{
	if (m_pTexture != nullptr)
	{
		for (uint32_t i = 0; i < (uint32_t)m_Lives; i++)
		{
			const auto pos = m_Transform.GetPosition();
			dae::Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x + (i * 20), pos.y, 20, 20);		
		}
	}
}


void LivesBar::PlayerDied()
{
	if (m_Lives > 0)
	{
		m_Lives--;
	}
}
