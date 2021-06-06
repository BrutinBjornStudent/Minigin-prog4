#pragma once




#include "BoardComponent.h"
#include "Component.h"


class QBertComponent :
    public BaseComponent
{
public:
	QBertComponent(glm::vec2 startcell, BoardComponent* boardRef, RenderComponent* renderRef);


	void Render() const override{};

	void Update(const float delta) override;


	void MoveTo(int x, int y);


private:
	glm::ivec2 m_Cellposition{0,0};

	float m_moveDelay = 0.3f;
	float m_TimePassedForMove = 0.f;
	
	glm::ivec2 m_nextPos{};

	BoardComponent* nm_pBoardComponent;
	RenderComponent* nm_pRenderComp;

	
	
};

