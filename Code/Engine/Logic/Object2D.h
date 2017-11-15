#pragma once
#ifndef _OBJECT2D_H_
#define _OBJECT2D_H_

#include "..\Base\Base.h"
#include "..\Base\Types.h"

//** Forwards declarations **
class CSprite;
//***************************

class CObject2D
{
protected:
	float		m_x,m_y;
	float		m_vx,m_vy;
	float		m_Width;
	float		m_Height;
	CSprite*	m_Sprite;
	bool		m_bVisible;

public:
	CObject2D(CSprite* Sprite)
		: m_x(0)
		, m_y(0)
		, m_vx(0)
		, m_vy(0)
		, m_Width(DEFAULT_SPRITE_WIDTH)
		, m_Height(DEFAULT_SPRITE_HEIGHT)
		, m_Sprite(Sprite)
		, m_bVisible(true)
	{}

	float	GetX() const									{return m_x;}
	float	GetY() const									{return m_y;}
	float	GetVX() const									{return m_vx;}
	float	GetVY() const									{return m_vy;}
	float	GetWidth() const								{return m_Width;}
	float	GetHeight() const								{return m_Height;}
	bool	IsVisible() const								{return m_bVisible;}
	void	SetX(const float x)								{m_x = x;}
	void	SetY(const float y)								{m_y = y;}
	void	SetVX(const float vx)							{m_vx = vx;}
	void	SetVY(const float vy)							{m_vy = vy;}
	void	SetWidth(const float Width)						{m_Width = Width;}
	void	SetHeight(const float Height)					{m_Height = Height;}
	void	SetPosition(const float x,const float y)		{m_x = x; m_y = y;}
	void	SetVelocity(const float vx,const float vy)		{m_vx = vx; m_vy = vy;}
	void	SetSize(const float Width, const float Height)	{m_Width = Width; m_Height = Height;}	
	void	SetVisible(const bool Visible)					{m_bVisible = Visible;}

	void	SetBounds(const float x,const float y, const float Width, const float Height);
	virtual void Update(float dt);
	virtual void Render();
};

#endif