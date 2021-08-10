#include "MiniginPCH.h"
#include "RectComponent.h"

#include "Renderer.h"


RectComponent::RectComponent()
	:m_Rectangle()
	,m_color(SDL_Color())
{
	
}

void RectComponent::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a )
{
	m_color.r = r;
	m_color.g = g;
	m_color.b = b;
	m_color.a = a;
}

void RectComponent::SetColor(SDL_Color color)
{
	m_color = color;
}

void RectComponent::Render() const
{
	
	dae::Renderer::GetInstance().RenderRect(&m_Rectangle,m_color);
}
