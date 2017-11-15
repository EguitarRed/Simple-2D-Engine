#pragma once
#ifndef _GUIELEMENT_H_
#define _GUIELEMENT_H_

#include "..\Base\Base.h"
#include "..\Base\Types.h"
#include <string>

class CGUIElement
{
protected:
	std::string m_Name;
	float		m_x,m_y;
	float		m_vx,m_vy;
	float		m_Width;
	float		m_Height;
	float		m_LiveTime;
	bool		m_bVisible;
	bool		m_bIsDead;

public:
	CGUIElement()
		: m_x(0)
		, m_y(0)
		, m_vx(0)
		, m_vy(0)
		, m_Width(100)
		, m_Height(20)
		, m_bVisible(true)
		, m_bIsDead(false)
		, m_Name("")
		, m_LiveTime(-9999.f)
	{}
	virtual ~CGUIElement()=0;

	float			GetX() const {return m_x;}
	float			GetY() const {return m_y;}	
	float			GetVX() const {return m_vx;}
	float			GetVY() const {return m_vy;}
	float			GetWidth() const {return m_Width;}
	float			GetHeight() const {return m_Height;}
	bool			IsVisible() const {return m_bVisible;}
	bool			IsDead() const {return m_bIsDead;}
	std::string		GetName() const {return m_Name;}
	float			GetLiveTime() const {return m_LiveTime;}
	void			SetX(const float x) {m_x = x;}
	void			SetY(const float y) {m_y = y;}	
	void			SetVX(const float vx) {m_vx = vx;}
	void			SetVY(const float vy) {m_vy = vy;}
	void			SetWidth(const float Width) {m_Width = Width;}
	void			SetHeight(const float Height) {m_Height = Height;}
	void			SetPosition(const float x,const float y) {m_x = x; m_y = y;}
	void			SetVelocity(const float vx,const float vy)		{m_vx = vx; m_vy = vy;}
	void			SetSize(const float Width, const float Height) {m_Width = Width; m_Height = Height;}
	void			SetBounds(const float x,const float y, const float Width, const float Height);
	void			SetVisible(const bool Visible) {m_bVisible = Visible;}
	void			SetIsDead(const bool Dead) {m_bIsDead = Dead;}
	void			SetName(const std::string Name) {m_Name = Name;}
	void			SetLiveTime(const float ftime) {m_LiveTime = ftime;}

	virtual void Update(float dt);
	virtual void Render()=0;
};

#endif