#include "QBertComponent.h"


QBertComponent::QBertComponent(glm::vec2 startcell, BoardComponent* boardRef, RenderComponent* renderRef)
	: m_Cellposition(startcell)
	, nm_pBoardComponent(boardRef)
	, nm_pRenderComp(renderRef)
{

	auto m_pos = nm_pBoardComponent->GetCellFromPos(startcell)->GetComponent<CellComponent>()->GetPosition();

	nm_pRenderComp->SetPosition(m_pos.x, m_pos.y);
}

void QBertComponent::Update(const float delta)
{
	m_TimePassedForMove += delta;
	if (m_TimePassedForMove > m_moveDelay)
	{
		m_TimePassedForMove = 0.f;

		std::cout << "new position" << m_nextPos.x << ":" << m_nextPos.y << std::endl;

		auto cell = nm_pBoardComponent->GetCellFromPos(m_nextPos);
		if (cell != nullptr) // check is player does not jump of the map.

		{
			auto spritePos = cell->GetComponent<CellComponent>()->GetPosition();
			
			m_Cellposition = m_nextPos;
			nm_pRenderComp->SetPosition(spritePos.x, spritePos.y);
			
		}
		

		
	}
	

	
}

void QBertComponent::MoveTo(int x, int y)
{

	std::cout << "move : x" << x << " , y:" << y << std::endl;
	m_nextPos.x = m_Cellposition.x + x;
	m_nextPos.y = m_Cellposition.y + y;
	
}
