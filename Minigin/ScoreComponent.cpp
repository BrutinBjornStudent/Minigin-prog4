#include "MiniginPCH.h"
#include "ScoreComponent.h"

ScoreComponent::ScoreComponent(dae::TextComponent* textcomp)
	:nm_pTextComp(textcomp)
	,m_needsUpdate(true)
	,m_score(50)
{
	
}

void ScoreComponent::Update(const float)
{
	if (m_needsUpdate && nm_pTextComp)
	{
		nm_pTextComp->SetText("" + std::to_string(m_score));
		m_needsUpdate = false;
	}
}

void ScoreComponent::Render() const
{
}
