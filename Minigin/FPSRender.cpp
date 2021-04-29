#include "MiniginPCH.h"
#include "FPSRender.h"
#include "ResourceManager.h"






FPSRender::FPSRender(std::shared_ptr<dae::TextObject>& textbox)
	:m_time{ 0 }
//	,m_timer{}
	,m_text{textbox}
{
}

FPSRender::~FPSRender()
{
}


void FPSRender::Update(float deltatime)
{

	m_time += deltatime;
	if (m_time > 1.f)
	{
//		m_text->SetText(std::to_string(m_timer.GetFPS()) + "FPS");
		m_time -=1.f;
	}
}

void FPSRender::Render() const
{

	m_text->Render();
}
