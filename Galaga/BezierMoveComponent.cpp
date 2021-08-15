#include "BezierMoveComponent.h"


#include <algorithm>
#include <glm/detail/func_geometric.inl>
#include <glm/detail/type_vec2.hpp>


/*
 *  https://javascript.info/bezier-curve
 *  https://nl.wikipedia.org/wiki/B%C3%A9zierkromme
	Bezier Calculation Example for 3 points:
	P= ( (1-t)^(2) *A) +
		 (2*t*(1-t)*B) +
		 t^(2)*C })
	A,B,C = punt
	t = tijd

	Bezier voorbeeld 4 punten
	
	P=Punt(
	(1-t)^(3) *A) +
	(3*(1-t)^(2)*t*B) +
	(3*(1-t)*t^(2)*C) +
	(t^(3) D)
	)
*/

BezierMoveComponent::BezierMoveComponent(std::vector<glm::vec2>& points, float duration)
	: m_CurrentBridges(points)
	, m_duration(duration)
{
}

void BezierMoveComponent::Update(const float deltatime)
{
	if (m_running)
	{
		m_ElapsedTime += deltatime;
		m_CurrentBridges = m_points;
		CalculateBridges();


		if (m_ElapsedTime >= m_duration)
		{
			m_ElapsedTime = 0.f;
			m_Done = true;
			m_running = false;
		}
	}
}

//recurcive loop.
void BezierMoveComponent::CalculateBridges()
{
	float m_Devision = m_ElapsedTime / m_duration;
	float m_OffsetDevision = float(m_ElapsedTime + 0.01)  / m_duration;
	m_Devision = std::clamp(m_Devision, 0.f, 1.f);
	m_OffsetDevision = std::clamp(m_OffsetDevision, 0.f, 1.f);
	
	if (m_CurrentBridges.size() == 2)
	{
		m_Point = (1 - m_Devision) * m_CurrentBridges[0] + m_Devision * m_CurrentBridges[1];
		m_Forward = (1 - m_OffsetDevision) * m_CurrentBridges[0] + m_OffsetDevision * m_CurrentBridges[1];
		m_Forward = m_Point - m_Forward;
		m_Forward = glm::normalize(m_Forward);
	}
	else
	{
		for (int i = 0; i < m_CurrentBridges.size() - 1;i++)
		{
			m_NewBridges.push_back((1- m_Devision)* m_CurrentBridges[i] + m_Devision * m_CurrentBridges[i+1]);
		}
		m_CurrentBridges = m_NewBridges;
		m_NewBridges.clear();
		CalculateBridges();
	}
}

