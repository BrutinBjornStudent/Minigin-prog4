#pragma once
#include <vector>
#include <glm/detail/type_vec2.hpp>



#include "Component.h"

//https://www.geometrictools.com/Documentation/MovingAlongCurveSpecifiedSpeed.pdf to read another time maybe

class BezierMoveComponent :
    public BaseComponent
{
public:
	BezierMoveComponent() = default;
	BezierMoveComponent(std::vector<glm::vec2>& points, float duration = 1);

	void Update(const float deltatime) override;
	void Render() const override {};

	glm::vec2 GetPoint() const { return m_Point; }
	glm::vec2 GetForward() const { return m_Forward; }
	void SetPoints(std::vector<glm::vec2> points) { m_points = points; }
	bool IsDone() { return m_running; }
	

	void SetRun(bool running) { m_running = running; };
private:
	void CalculateBridges();
	
	std::vector<glm::vec2> m_points;
	std::vector<glm::vec2> m_CurrentBridges;
	std::vector<glm::vec2> m_NewBridges;
	glm::vec2 m_Point;
	glm::vec2 m_Forward;
	
	float m_duration = 1.f; 
	float m_ElapsedTime = 0.f;
	bool m_running = false;
	bool m_Done = false;
};

