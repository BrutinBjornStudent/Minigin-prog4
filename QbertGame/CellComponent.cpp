#include "CellComponent.h"

#include <SDL.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>

//https://www.redblobgames.com/grids/hexagons/

CellComponent::CellComponent(const glm::vec3& pos, const glm::ivec3& boardPos, const SDL_Color& color, float rad)
	:m_radius(rad)
	, m_color(color)
	, m_colorBottomRight{ 0,0,100,255 }
	,m_colorBottomLeft{0,0,255,255}
	, m_coordinate(boardPos)
	, m_topRight(0, 0)
	, m_top(0, 0)
	, m_topLeft(0,0)
	, m_bottomright(0,0)
	, m_bottomleft(0,0)

	
{
	m_Transform.SetPosition(pos);

	const glm::vec3& posRef = m_Transform.GetPosition();

	m_top = glm::vec2(posRef.x, posRef.y - m_radius);

	m_bottom = glm::vec2(posRef.x, posRef.y + m_radius);
	
	m_topRight = glm::vec2(posRef.x + m_radius * sinf(float(M_PI) / 180.f * 60.f), 
		posRef.y - m_radius * cosf(float(M_PI) / 180.f * 60.f));
	
	m_topLeft = glm::vec2(posRef.x - m_radius * sinf(float(M_PI) / 180.f * 60.f), 
		posRef.y - m_radius * cosf(float(M_PI) / 180.f * 60.f));

	m_bottomright = glm::vec2(posRef.x + m_radius * sinf(float(M_PI) / 180.f * 60.f), 
		posRef.y + m_radius * cosf(float(M_PI) / 180.f * 60.f));

	m_bottomleft = glm::vec2(posRef.x - m_radius * sinf(float(M_PI) / 180.f * 60.f),
		posRef.y + m_radius * cosf(float(M_PI) / 180.f * 60.f));
	
}

void CellComponent::Render() const
{


	const glm::vec3& posRef = m_Transform.GetPosition();
	

	glBegin(GL_POLYGON);

	
	glColor3f(m_color.r,m_color.g,m_color.b);
	//top part
	glVertex2f(posRef.x, posRef.y);// center
	glVertex2f(m_topLeft.x,m_topLeft.y); //left
	glVertex2f(m_top.x,m_top.y); //far
	glVertex2f(m_topRight.x,m_topRight.y);//right
	glEnd();
	// end top part

	//bottom right
	glBegin(GL_POLYGON);
	glColor3f
		(float(m_colorBottomRight.r /255.f), float(m_colorBottomRight.g/255.f), float(m_colorBottomRight.b/255.f));
	glVertex2f(posRef.x, posRef.y);
	glVertex2f(m_topRight.x,m_topRight.y);
	glVertex2f(m_bottomright.x, m_bottomright.y);
	glVertex2f(m_bottom.x, m_bottom.y);
	glVertex2f(posRef.x, posRef.y);
	glEnd();
	//end bottom right


	//end bottom left
	glBegin(GL_POLYGON);
	glColor3f
		(float(m_colorBottomLeft.r/255.f), float(m_colorBottomLeft.g/255.f), float(m_colorBottomLeft.b/255.f));
	glVertex2f(posRef.x, posRef.y);
	glVertex2f(m_bottom.x, m_bottom.y);
	glVertex2f(m_bottomleft.x, m_bottomleft.y);
	glVertex2f(m_topLeft.x, m_topLeft.y);
	glVertex2f(posRef.x, posRef.y);
	glEnd();
	//end bottom left


	

	//glColor3f(1.f, 1.f, 1.f);			old pentagram code
	//glBegin(GL_LINE_LOOP);
	//for (int i = 0; i < 5; i++)
	//{
	//	glVertex2f(center.x + sinf(float(M_PI) / 180.f * i * 144.f + startAngle) * radius,
	//		center.y + cosf(float(M_PI) / 180.f * i * 144.f + startAngle) * radius);
	//}
	//glEnd();
	
}
