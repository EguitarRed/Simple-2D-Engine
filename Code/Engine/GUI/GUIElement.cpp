#include "GUIElement.h"


CGUIElement::~CGUIElement(){}

void CGUIElement::SetBounds(const float x,const float y, const float Width, const float Height)
{
	m_x = x;
	m_y = y;
	m_Width = Width;
	m_Height = Height;
}

void CGUIElement::Update(float dt)
{
	m_x += m_vx * dt;
	m_y += m_vy * dt;
	if (m_LiveTime > 0.f)
	{
		m_LiveTime -= dt;		
	}
	if ((m_LiveTime > -9999.f) && (m_LiveTime <= 0.f))
		m_bIsDead = true;
}