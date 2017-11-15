#pragma once
#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "..\Base\Base.h"
#include "..\Base\Types.h"
#include <string>

class CLevel
{
protected:
	std::string		m_LevelName;
	int32			m_x,m_y;
	int32			m_Width;
	int32			m_Height;
public:
	CLevel()
		: m_LevelName("Level01")
		, m_x(0)
		, m_y(0)
		, m_Width(DEFAULT_HRES)
		, m_Height(DEFAULT_VRES)
	{}

	std::string GetLevelName() const {return m_LevelName;}
	void SetLevelName(const std::string LevelName) {m_LevelName = LevelName;}
	int32	GetX() const {return m_x;}
	int32	GetY() const {return m_y;}	
	int32	GetWidth() const {return m_Width;}
	int32	GetHeight() const {return m_Height;}	
	void	SetX(const int32 x) {m_x = x;}
	void	SetY(const int32 y) {m_y = y;}	
	void	SetWidth(const int32 Width) {m_Width = Width;}
	void	SetHeight(const int32 Height) {m_Height = Height;}
	void	SetPosition(const int32 x,const int32 y) {m_x = x; m_y = y;}
	void	SetSize(const int32 Width, const int32 Height) {m_Width = Width; m_Height = Height;}
	void	SetBounds(const int32 x,const int32 y, const int32 Width, const int32 Height);	

	virtual void Update(float dt)=0;
};


#endif