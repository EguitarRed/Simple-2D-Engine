#include "Object2D.h"
#include "SDL.h"
#include "..\Graphics\Sprite.h"


void CObject2D::SetBounds(const float x,const float y, const float Width, const float Height)
{
	m_x = x;
	m_y = y;
	m_Width = Width;
	m_Height = Height;
}

void CObject2D::Update(float dt)
{
	m_x += m_vx * dt;
	m_y += m_vy * dt;
}

void CObject2D::Render()
{
	if (m_bVisible && (m_Sprite != NULL))
	{
		m_Sprite->Render(int32(m_x), int32(m_y), int32(m_Width), int32(m_Height));
	}
}