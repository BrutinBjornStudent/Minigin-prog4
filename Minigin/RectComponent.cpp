#include "MiniginPCH.h"
#include "RectComponent.h"

#include "Renderer.h"


RectComponent::RectComponent()
	:m_Rectangle()
{
}

void RectComponent::Render() const
{
	dae::Renderer::GetInstance().RenderRect(&m_Rectangle);
}
